#pragma once

#include <queue>
#include "cpuprocess.h"

class CPUQueue
{
public:
	CPUQueue()
	{
	}

	~CPUQueue()
	{
	}

	CPUProcess pop();
	void push(const CPUProcess& process);
	void setMaxCount(int mCount) { maxCount = mCount; }
	int getMaxCount() { return maxCount; }

	int size() {
		return queue.size();
	}

	void clear() {
		std::queue<CPUProcess> empty;
		std::swap(queue, empty);
	}

private:
	std::queue<CPUProcess> queue;
	int maxCount = 0;
};