#include "cpuqueue.h"
#include "cpuprocess.h"

CPUProcess CPUQueue::pop()
{
	CPUProcess & process = queue.front();
	queue.pop();
	return process;
}

void CPUQueue::push(const CPUProcess& process)
{
	queue.push(process);
}
