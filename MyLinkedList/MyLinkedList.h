#ifndef _MYLINKEDLIST_H
#include <iostream>
#include <string>

using namespace std;

typedef struct _tnode {
	int id;
	string name;
	int y, m, d;
	struct _tnode* next;
}TNODE;

class MyLinkedList {
	TNODE* head;
public:
	MyLinkedList() { head = NULL; }
	~MyLinkedList();
	void addNode(int _id, string _name, int _y, int _m, int _d);
	void addNode(TNODE* node);
	void insertNode(int _id, int myid, string _name, int _y, int _m, int _d);
	void insertNode(TNODE* _node, TNODE* node);
	void deleteNodes();
	void deleteNode(int);
	TNODE* searchNode(int id);
	void display();
};
#endif