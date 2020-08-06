#include "MyLinkedList.h"

int main(void)
{
	{
		MyLinkedList l;

		l.addNode(0, "John", 2000, 1, 1);
		l.addNode(1, "Mike", 2010, 10, 10);
		l.addNode(2, "Tom", 2011, 10, 11);
		l.addNode(3, "Jake", 2012, 10, 12);
		l.addNode(4, "Lee", 2013, 10, 13);

		l.display();

		l.insertNode(1, 10, "Kim", 2010, 9, 1);

		l.display();
		l.deleteNode(10);
		cout << endl;
	}
}