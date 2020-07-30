#include <algorithm>
#include <iostream>

using namespace std;

class Polynomial;

class Term
{
	friend Polynomial;
private:
	float coef;
	int exp;
};

class Polynomial {
public:
	Polynomial();
	//construct the polynomial p(x) = 0;

	Polynomial Add(Polynomial b);
	//return the sum of the polynomials *this and b

	void NewTerm(const float theCoeff, const int theExp);
	int Display();
	int GetData();
private:
	static Term* termArray;
	static int capacity;
	static int free;
	int start, finish;
	int terms;
};

Term* Polynomial::termArray = new Term[100];
int Polynomial::capacity = 0;
int Polynomial::free = 0;

Polynomial::Polynomial()
{
	start = free;

}
int Polynomial::Display() {

	return 0;
}
//Program 2.9: Adding a new term
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	if (terms == capacity)
	{
		capacity *= 2;
		Term* temp = new Term[capacity];
		copy(termArray, termArray + free, temp);
		delete[] termArray;
		termArray = temp;
	}
	termArray[free].coef = theCoeff;
	termArray[free++].exp = theExp;
}

int Polynomial::GetData() {
	int i, degree;
	float coef;
	int expo;
	//���� �����Ͽ� ������ ����� �Է�, 0<= ���� <= 5, 0<= ��� < 100
	finish = free - 1;
	terms = finish - start + 1;
	return 0;
}

//program 2.8: Adding two polynomials
//���� 91 ������ ����� �ٸ� �ڵ� Ȯ���ϱ�
Polynomial Polynomial::Add(Polynomial b)
{

	return c;
}


int main(void) {
	int choice;


	Polynomial P1, P2, P3, P4;
	return 0;
}