#include <thread>
#include <iostream>
#include <queue>
#include <chrono>


class CPUQueue;
class CPUProcess;
class CPU;

#pragma once
#include <functional>
#include <thread>
#include <list>
#include <mutex>
#include <memory>
#include <condition_variable>

std::mutex m;




//void CPU::treatProcess()
//{
//	while (1)
//	{
//		busy = true;
//		m.lock();
//		Process currProcess = queue->pop();
//		m.unlock();
//		std::cout << "New process comming, treation for" << currProcess.time.count() << std::endl;
//		std::this_thread::sleep_for(currProcess.time);
//		busy = false;
//	}
//}
//
//void CPU::startTreation()
//{
//	cpuThread.join();
//}

//void CPUProcess::setTime(const std::chrono::milliseconds & msec)
//{
//	this->m_time = msec;
//}
//
//std::chrono::milliseconds CPUProcess::time() const
//{
//	return m_time;
//}
