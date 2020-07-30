#include <iostream>
#include <ctime>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

using namespace std;

class Matrix {
private:
	static int* data;
	static int free;
	int rows;
	int cols;
	int start;
	int finish;
public:
	Matrix(int, int);
	void get_data();
	void show_data();
	void sort_data();
	Matrix& add(Matrix&);
	Matrix& multiply(Matrix, Matrix);
};

int Matrix::free = 0;
int* Matrix::data = new int[100];

Matrix::Matrix(int row, int col) {
	rows = row;
	cols = col;
	start = free;
	finish = start + rows * cols;
	free += rows * cols;
}

void Matrix::get_data()
{
	//for (int i = 0; i < rows; ++i)
	//	for (int j = 0; j < cols; ++j)
	//		data[start + i * cols + j] = rand() % 10;
	for (int i = start; i < finish; ++i)
		data[i] = rand() % 10;
}

void Matrix::show_data()
{
	//for (int i = 0; i < rows; ++i) {
	//	for (int j = 0; j < cols; ++j)
	//		cout << data[start + i * cols + j] << ' ';
	//	cout << endl;
	//}
	//cout << endl;
	for (int i = start; i < finish; ++i) {
		cout << data[i] << ' ';
		if ((i - start + 1) % cols == 0)
			cout << endl;
	}
	cout << endl;
}

void Matrix::sort_data()
{
	//int tmp;
	//for (int i = 0; i < rows * cols - 1; ++i) {
	//	for (int j = i; j < rows * cols; ++j) {
	//		if (data[start + i] > data[start + j]) {
	//			tmp = data[start + j];
	//			data[start + j] = data[start + i];
	//			data[start + i] = tmp;
	//		}
	//	}
	//}

	int tmp;
	for (int i = start; i < finish - 1; ++i) {
		for (int j = i; j < finish; ++j) {
			if (data[i] > data[j]) {
				tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
	}
}

Matrix& Matrix::add(Matrix& a)
{
	//if (rows != a.rows || cols != a.cols)
	//	return a;
	//else {
	//	for (int i = 0; i < rows; ++i)
	//		for (int j = 0; j < cols; ++j)
	//			data[start + i * cols + j] += a.data[start + i * cols + j];
	//	return *this;
	//}

	if (rows != a.rows || cols != a.cols)
		return a;
	else {
		for (int i = start, j = a.start; i < finish && j < a.finish; ++i, ++j)
			data[i] += a.data[j];
		return *this;
	}
}

Matrix& Matrix::multiply(Matrix a, Matrix b)
{
	int sum;
	if (a.cols != b.rows) {
		cout << "Not Match!" << endl;
		return a;
	}
	else {
		for (int i = 0; i < a.rows; ++i) {
			for (int j = 0; j < b.cols; ++j) {
				sum = 0;
				for (int k = 0; k < b.rows; ++k) {
					sum += a.data[a.start + i * a.cols + k] * b.data[b.start + k * b.cols + j];
				}
				data[start + i * b.cols + j] = sum;
			}
		}
		return *this;
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	Matrix a(AROWS, ACOLS);
	Matrix b(AROWS, ACOLS);
	Matrix c(AROWS, CCOLS);

	a.get_data();
	b.get_data();
	a.show_data();
	b.show_data();

	a.add(b);
	a.show_data();

	return 0;
}