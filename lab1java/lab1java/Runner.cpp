#include "Runner.h"


void Runner::start() {
	int i = 0;
	int failed = 0;
	do
	{
		while (i < NUM_PROC) {
			CPUProcess newProcess(getRandomNumber(0, 10));

			if (!cpu1.isBusy()) {
				if (queue.size() > 0) {
					cpu1.loadProcess(queue.pop());
					queue.push(newProcess);
					std::cout << cpu1.procName() << "new process #" << newProcess.getId() << " generated but there is another process waiting in queue, new process pushed in queue" << std::endl;
				}
				else {
					cpu1.loadProcess(newProcess);
				}
			}
			else if (!cpu2.isBusy()) {
				if (queue.size() > 0) {
					cpu2.loadProcess(queue.pop());
					queue.push(newProcess);
					std::cout << cpu2.procName() << "new process #" << newProcess.getId() << "generated but there is another process waiting in queue, new process pushed in queue" << std::endl;
				}
				else {
					cpu2.loadProcess(newProcess);
				}

			}
			else {
				if (queue.size() < queue.getMaxCount()) {
					queue.push(newProcess);
					std::cout << "Processes #1 and #2 are busy. Process #" << newProcess.getId() << " has been pushed in queue" << std::endl;
				}
				else {
					std::cout << "Processes #1 and #2 are busy, queue is full. Process #" << newProcess.getId() << " has been deleted" << std::endl;
					failed++;
				}
			}
			i++;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}

		if (i >= NUM_PROC) {
			if (!cpu1.isBusy()) {
				if (queue.size() > 0) {
					cpu1.loadProcess(queue.pop());
				}
			}
			else if (!cpu2.isBusy()) {
				if (queue.size() > 0) {
					cpu2.loadProcess(queue.pop());
				}
			}
			else if (queue.size() > queue.getMaxCount()) {
				std::cout << "Processes #1 and #2 are busy, queue is full. Process #" << queue.pop().getId() << " has been deleted" << std::endl;
				failed++;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(2000));


		}


	} while (queue.size() > 0);
	cpu1.stop();
	cpu2.stop();
	std::cout << "failed processes percent: " << failed / (double)NUM_PROC * 100 << std::endl;
}

int Runner::getRandomNumber(int min, int max) {
	srand(time(nullptr));
	int tmp = min + (rand() % (max - min + 1));
	std::cout << "Random number is: " << tmp << std::endl;
	return tmp;
}