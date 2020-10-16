//#include "lab1java.cpp"
#include "cpu.h"
#include "cpuprocess.h"
#include "cpuqueue.h"
#include <Windows.h>
#include "Runner.h"

//#define FIRST_LAB_ENABLE
#define SECOND_LAB_ENABLE

int main()
{
#ifdef FIRST_LAB_ENABLE



	time_t start = clock();
	fillMatrix(matrix);
	//showMatrix(matrix);
	// std::cout << '\n';
	flipSide(matrix);
	std::cout << "Time taken " << ((clock() - start) / (double)CLOCKS_PER_SEC) << std::endl;
	//showMatrix(matrix);
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		threads.push_back(std::thread(routine, i, matrix));
	}
	start = clock();
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	std::cout << "time taken(threaded) " << ((clock() - start) / (double)CLOCKS_PER_SEC) << std::endl;
	//showMatrix(matrix);
#endif // FIRST_LAB_ENABLE
#ifdef SECOND_LAB_ENABLE
	Runner runner;

	

#endif // SECOND_LAB_ENABLE

}