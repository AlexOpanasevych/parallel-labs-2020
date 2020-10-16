#pragma once

#include "cpuqueue.h"
#include <thread>
#include "cpuprocess.h"
#include <mutex>
#include <iostream>

class CPU {

	bool busy;
	std::string processorName;

	CPUProcess workingProcess;

	std::mutex m;

	std::thread thr;
	bool running = true;
public:
	CPU(std::string name) : thr(&CPU::func, this) {
		processorName = name;
	}

	std::string procName() { return processorName; }

	~CPU() {
		if (thr.joinable()) {
			thr.join();
		}
	}

	void stop() {
		running = false;
		if (thr.joinable()) {
			thr.join();
		}
	}

	bool isBusy() {
		return this->busy;
	}

	void loadProcess(const CPUProcess & process) {
		m.lock();
		workingProcess = process;
		m.unlock();
	}

	void func() {
		while (running) {
			if (workingProcess.getId() != -1) {
				std::cout << "Start working: processor " << processorName << " with process #" << workingProcess.getId() << std::endl;
				busy = true;
				std::this_thread::sleep_for(std::chrono::milliseconds(abs(workingProcess.getComplexity()) * 1000 + 1300));
				this->busy = false;
				std::cout << "Finished work: processor " << processorName << " with process #" << workingProcess.getId() << std::endl;
				m.lock();
				workingProcess.setId(-1);
				m.unlock();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		}
	}
};

