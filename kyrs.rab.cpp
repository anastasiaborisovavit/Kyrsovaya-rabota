#define _CRT_SECURE_NO_WARNINGS
#define _CTR_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <random>
#include <locale>
#include <malloc.h>

void input(int size, int **mat) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				mat[i][j] = rand() % 2;
				if (mat[i][j] == 0)
					mat[i][j] = mat[i][j];
				else
					mat[i][j] = 1 + rand() % 100;
			}
			mat[j][i] = mat[i][j];
		}
	}
}
void input2(int size, int **mat) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				scanf_s("%d", &mat[i][j]);
			}
			mat[j][i] = mat[i][j];
		}
	}
}
void output(FILE *file, int size, int **mat) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d", mat[i][j]);
			fprintf(file, "%4d", mat[i][j]);
		} printf("\n");
		fprintf(file, "\n");
	}
}
void izol(FILE *file, int size, int **mat, int *mas) {
	int e;
	for (int i = 0; i < size; i++) {
		int iz = 0;
		for (int j = 0; j < size; j++) {
			if (mat[i][j] != 0) {
				iz += 1;
			}
		}

		mas[i] = iz;
	}
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i] == 0) {
			printf("\nВершина %d является изолированной", i + 1);
			fprintf(file, "\nВершина %d является изолированной", i + 1);
			printf("\n");
			e = i;
			flag = 1;
		}

	}
	if (flag == 1) {
		{
			mat[e][1] = 1;
			mat[1][e] = mat[e][1];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%4d", mat[i][j]);
				fprintf(file, "%4d", mat[i][j]);
			} printf("\n");
			fprintf(file, "\n");
		}
		printf("\nВершина больше не является изолированной");
		fprintf(file, "\nВершина больше не является изолированной");
	}
	if (flag == 0) {
		printf("Матрица не имеет изолированных вершин!");
		fprintf(file, "Матрица не имеет изолированных вершин!");
	}
	printf("\n");
	fprintf(file, "\n");
}

int main() {
	FILE *file;
	int number;
	int **mat;
	int *mas;
	int size;
	setlocale(LC_ALL, "Russian");
	printf("Добро пожаловать! Эта программа для поиска изолированных вершин в графе.");
	int t = 0;
	int k = 0;
	int number1;
	while (t < 1) {
		printf("\n Выберете опцию:");
		printf("\n 1)Начать выполнение программы");
		printf("\n 0)Завершить выполнение программы");
		printf("\n");
		scanf_s("%d", &number);
		if (number == 1) {
			t = t + 1;
			printf("Вы выбрали опцию Начать");
			while (k < 1) {
				printf("\n Выберете опцию:");
				printf("\n 1)Автоматичекая генерация");
				printf("\n 0)Ручная генерация");
				printf("\n");
				scanf_s("%d", &number1);
				if (number1 == 1) {
					k = k + 1;
					printf("Вы выбрали автоматическую генерацию:");
					printf("\n");
					printf("Введите размер матрицы:");
					scanf_s("%d", &size);
					mat = (int**)malloc(size * sizeof(int*));
					for (int i = 0; i < size; i++) {
						mat[i] = (int*)malloc(size * sizeof(int));
					}
					mas = (int*)malloc(size * sizeof(int));
					input(size, mat);
					file = fopen("file.txt", "w");
					fprintf(file, "Матрица:");
					fprintf(file, "\n");
					output(file, size, mat);
					izol(file, size, mat, mas);
					fclose(file);
					break;
				}
				if (number1 == 0) {
					k = k + 1;
					printf("Вы выбрали ручную генерацию:");
					printf("\n");
					printf("Введите размер матрицы:");
					scanf_s("%d", &size);
					printf("Введите элементы матрицы:");
					mat = (int**)malloc(size * sizeof(int*));
					for (int i = 0; i < size; i++) {
						mat[i] = (int*)malloc(size * sizeof(int));
					}
					mas = (int*)malloc(size * sizeof(int));
					input2(size, mat);
					file = fopen("file.txt", "w");
					fprintf(file, "Матрица:");
					fprintf(file, "\n");
					output(file, size, mat);
					izol(file, size, mat, mas);
					fclose(file);
					break;
				}
				else
					printf("Ошибка! Попробуйте выбрать ещё раз");
			}
			if (k = 1) {
				break;
			}
		}
		if (number == 0) {
			t = t + 1;
			printf("Вы выбрали опцию Завершить");
			break;
		}
		else
			printf("Ошибка! Попробуйте выбрать ещё раз");
	}
	getchar();
	getchar();
	return 0;
}
