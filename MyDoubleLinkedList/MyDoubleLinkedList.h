#ifndef __MYDOUBLELINKEDLIST_H_
#define __MYDOUBLELINKEDLIST_H_
#include <iostream>
#include <string>

using namespace std;

typedef struct _dnode {
	int id;
	string name;
	int y, m, d;
	struct _dnode* prev;
	struct _dnode* next;
}DNODE;

class MyDoubleLinkedList {
	DNODE* head;
public:
	MyDoubleLinkedList() { head = NULL; };
	~MyDoubleLinkedList();
	void addNodeBack(int id, string name, int y, int m, int d);
	void addNodeBack(DNODE* node);
	void addNodeFront(int id, string name, int y, int m, int d);
	void addNodeFront(DNODE* node);
	void insertNode(int id, int myid, string name, int y, int m, int d);
	void insertNode(DNODE* _node, DNODE* node);
	void deleteNode(int n);
	DNODE* searchNode(int id);
	void displayFoward();
	void displayBackward();
};

#endif