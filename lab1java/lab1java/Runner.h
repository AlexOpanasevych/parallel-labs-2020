#pragma once

#include "cpu.h"
#include "cpuqueue.h"
#include <iostream>

constexpr auto NUM_PROC = 20;
constexpr auto MAX_Q_SIZE = 5;

class Runner
{
	CPU cpu1;
	CPU cpu2;
	CPUQueue queue;
public:
	int getRandomNumber(int min, int max);

	Runner() : cpu1("Processor 1"), cpu2("Processor 2") {
		queue.setMaxCount(MAX_Q_SIZE);
		start();
	}

	void start();
};

