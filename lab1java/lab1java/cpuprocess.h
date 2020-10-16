#pragma once

class CPUProcess
{
public:
	CPUProcess(int complexity)
	{
		this->complexity = complexity;
		this->id = nextId++;
	}

	CPUProcess() {}

	//CPUProcess(const CPUProcess& other) {
	//	queue = new 
	//	queue = other
	//	queue->setMaxCount(other.queue->getMaxCount());
	//}

	//CPUProcess& operator=(const CPUProcess& other) {
	//	if (queue == nullptr) {
	//		queue = new CPUQueue();
	//	}
	//	else queue->clear();
	//	queue->setMaxCount(other.queue->getMaxCount());
	//}

	~CPUProcess()
	{
	}
	int getComplexity() {
		return complexity;
	}

	int getId() {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	static int nextId;
private:
	int id = -1;
	int complexity;

};