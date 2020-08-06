#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

#define N 30

using namespace std;

template <typename T>int get_data(T p, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			p[i][j] = rand() % r * c;
	return 1;
}

template <typename T>void show_data(T p, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%3d ", p[i][j]);
		printf("\n");
	}
	printf("\n");
}

void SelectionSort(int* a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j]) j = k;
		swap(a[i], a[j]);
	}
}
void swap(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}

int sort(int(*p)[N], int n)
{
	int one[N * N];
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			one[r * N + c] = p[r][c];
	SelectionSort(one, n * n);
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			p[r][c] = one[r * N + c];

	return 1;
}

//int sort(int(*p)[N], int n)
//{
//	int mode = 0;
//	int k;
//	for (int r = 0; r < n; r++)
//		for (int c = 0; c < n; c++)
//		{
//			for (int i = r; i < n; i++)
//			{
//				if (!mode)
//					k = c + 1;
//				else k = 0;
//				if (k == n) {
//					k = 0; mode = 1;
//					continue;
//				}
//				for (int j = k; j < n; j++)
//				{
//					//cout << "r = " << r << "c == " << c << "i = " << i << "j = " << j << endl;
//					if (p[r][c] > p[i][j])
//					{
//						int temp = p[r][c];
//						p[r][c] = p[i][j];
//						p[i][j] = temp;
//					}
//				}
//				mode = 1;
//			}
//			mode = 0;
//		}
//
//	return 1;
//}

int sequentialSearch(int(*e)[N], int x, const int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (e[i][j] == x)
				return i * n + j;
		}
	}
	return -1;
}

int binarySearch(int(*e)[N], int x, const int n)
{
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

void multiply(int a[10][20], int b[20][30], int c[10][30])
{
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < N; ++j) {
			sum = 0;
			for (int k = 0; k < 20; ++k) 
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}
}


int main(void)
{
	int element[N][N];

	int a[10][20];
	int b[20][30];
	int c[10][30];
	
	//1Àå
	//get_data(element, N, N);
	//show_data(element, N, N);
	//sort(element, N);
	//show_data(element, N, N);
	//scanf("%d", &key);
	//while (sequentialSearch(element, key, N) == -1)
	//	scanf("%d", &key);
	//while (binarySearch(element, key, N) == -1)
	//	scanf("%d", &key);

	//2Àå
	get_data(a, 10, 20);
	show_data(a, 10, 20);
	get_data(b, 20, 30);
	show_data(b, 20, 30);
	multiply(a, b, c);
	show_data(c, 10, 30);
	return 1;
}