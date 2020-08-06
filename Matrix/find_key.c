#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void get_data(int(*e)[N], int);
void show_data(int(*e)[N], int);
void sort(int(*e)[N], int);
void sort2(int(*e)[N], int);
int search(int(*e)[N], int, const int);

int main(void)
{
	srand((unsigned)time(NULL));
	int element[N][N];
	int key;
	
	get_data(element, N);
	sort(element, N);
	show_data(element, N);
	
	scanf("%d", &key);
	while (search(element, key, N) == -1)
		scanf("%d", &key);
	return 0;
}

void get_data(int(*e)[N], int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			e[i][j] = rand() % 900 + 1;
}

void show_data(int(*e)[N], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%3d ", e[i][j]);
		printf("\n");
	}	
	printf("\n");
}

void sort(int(*e)[N], int n)
{
	int temp[N * N] = { 0, };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			temp[i * n + j] = e[i][j];
	}

	for (int i = 0; i < n * n; i++)
	{
		int t;
		int j = i;
		for (int k = i + 1; k < n * n; k++)
			if (temp[k] < temp[j])
				j = k;
		t = temp[i];
		temp[i] = temp[j];
		temp[j] = t;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			e[i][j] = temp[i * n + j];
	}
}

void sort2(int(*e)[N], int n) {
	int min_i, min_j;
	int tmp;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			min_i = i; min_j = j;
			for (int x = i; x < n; ++x) {
				for (int y = j; y < n; ++y) {
					if (e[min_i][min_j] > e[x][y]) {
						min_i = x; min_j = y;
					}
				}
			}
			tmp = e[i][j];
			e[i][j] = e[min_i][min_j];
			e[min_i][min_j] = tmp;
		}
	}
}

int search(int (*e)[N], int x, const int n) {
	int temp[N * N];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			temp[i * n + j] = e[i][j];
	}

	int left = 0, right = n * n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < temp[middle]) right = middle - 1;
		else if (x > temp[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}