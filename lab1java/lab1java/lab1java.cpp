#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <ctime>
#define MATRIX_SIZE 20000
#define NUM_THREADS std::thread::hardware_concurrency()


int matrix[MATRIX_SIZE][MATRIX_SIZE];
std::vector<std::thread> threads;

void showMatrix(int matrix[][MATRIX_SIZE]) {

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void fillMatrix(int matrix[][MATRIX_SIZE]) {
	srand(time(nullptr));
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void flipSide(int matrix[][MATRIX_SIZE]) {
	int half = MATRIX_SIZE / 2;
	for (int i = 0; i < half; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrix[half + i][j] = matrix[i][j];
		}
	}
}

void fillMatrixThreaded(int id, int matrix[][MATRIX_SIZE]) {
	for (int i = id * (MATRIX_SIZE / NUM_THREADS); i < (id + 1) * (MATRIX_SIZE / NUM_THREADS); i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void flipSideThreaded(int id, int matrix[][MATRIX_SIZE]) {
	int half = MATRIX_SIZE / 2;
	int endPoint = half + ((half / NUM_THREADS) * (id + 1));
	int startPoint = half + (half / NUM_THREADS * id);
	if (id == NUM_THREADS - 1 && endPoint < MATRIX_SIZE) {
		endPoint += MATRIX_SIZE % NUM_THREADS;
	}
	for (int i = startPoint; i < endPoint; i++) {

		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrix[i][j] = matrix[i - half][j];
		}
	}
}

void routine(int id, int matrix[][MATRIX_SIZE]) {
	fillMatrixThreaded(id, matrix);
	flipSideThreaded(id, matrix);
}