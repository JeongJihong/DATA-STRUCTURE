#include "MyDoubleLinkedList.h"

int main(void)
{
	{
		MyDoubleLinkedList d;

		d.addNodeFront(4, "John", 2000, 1, 1);
		d.addNodeFront(3, "Mike", 2010, 10, 10);
		d.addNodeFront(2, "Tom", 2011, 10, 11);
		d.addNodeFront(1, "Jake", 2012, 10, 12);
		d.addNodeFront(0, "Lee", 2013, 10, 13);
		d.addNodeBack(5, "Park", 2014, 2, 3);
		d.addNodeBack(6, "Kim", 2014, 11, 23);
		d.addNodeBack(7, "Jeong", 2015, 8, 19);

		d.displayBackward();

		d.insertNode(1, 10, "Kim", 2010, 9, 1);
		d.displayBackward();

		d.deleteNode(0);
		d.deleteNode(10);
		d.deleteNode(7);
		d.displayBackward();

		return 0;
	}
}