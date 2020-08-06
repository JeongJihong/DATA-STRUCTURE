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
	int* m;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int, int);
	void get_data();
	void show_data();
	void sort_data();
	Matrix& add(Matrix&);
	Matrix& multiply(Matrix, Matrix);
};

Matrix::Matrix() {
	rows = 0;
	cols = 0;
}

Matrix::Matrix(int row, int col) {
	rows = row;
	cols = col;
	m = new int[rows * cols];
}

void Matrix::get_data()
{
	for (int i = 0; i < rows; ++i) 
		for(int j = 0; j < cols; ++j)
			m[i * cols + j] = rand() % 10 + 1;
}

void Matrix::show_data()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			cout << m[i * cols + j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void Matrix::sort_data()
{
	int tmp;
	for (int i = 0; i < rows * cols - 1; ++i) {
		for (int j = i; j < rows * cols; ++j) {
			if (m[i] > m[j]) {
				tmp = m[j];
				m[j] = m[i];
				m[i] = tmp;
			}
		}
	}
}

Matrix& Matrix::add(Matrix& a)
{
	if (rows != a.rows || cols != a.cols)
		return a;
	else {
		for (int i = 0; i < rows; ++i) 
			for (int j = 0; j < cols; ++j)
				m[i * cols + j] += a.m[i * cols + j];
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
					sum += a.m[i * a.cols + k] * b.m[k * b.cols + j];
				}
				m[i * b.cols + j] = sum;
			}
		}
		return *this;
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	Matrix a(AROWS, ACOLS);
	Matrix b(BROWS, BCOLS);
	Matrix c(AROWS, CCOLS);

	a.get_data();
	b.get_data();
	a.show_data();
	b.show_data();
	c.multiply(a, b);
	c.show_data();

	return 0;
}