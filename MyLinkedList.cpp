#include "MyLinkedList.h"

MyLinkedList::~MyLinkedList() { deleteNodes(); }

void MyLinkedList::addNode(int _id, string _name, int _y, int _m, int _d)
{
	TNODE* newNode = new TNODE;
	newNode->id = _id;
	newNode->name = _name;
	newNode->y = _y;
	newNode->m = _m;
	newNode->d = _d;
	newNode->next = NULL;
	addNode(newNode);
}

void MyLinkedList::addNode(TNODE* node)
{
	TNODE* p = head;
	if (p == NULL) {
		head = node;
		return;
	}
	while (p->next != NULL) 
		p = p->next;
	p->next = node;
}

void MyLinkedList::insertNode(int _id, int myid, string _name, int _y, int _m, int _d)
{
	TNODE* newNode = new TNODE;
	newNode->id = myid;
	newNode->name = _name;
	newNode->y = _y;
	newNode->m = _m;
	newNode->d = _d;
	newNode->next = NULL;
	insertNode(searchNode(_id), newNode);
}

void MyLinkedList::insertNode(TNODE* _node, TNODE* node)
{
	TNODE* p = _node->next;
	_node->next = node;
	node->next = p;

}

void MyLinkedList::deleteNodes()
{
	TNODE* node = head;
	while (node) {
		node = node->next;
		cout << "delete " << head->id << endl;
		delete head;
		head = node;
	}
}

void MyLinkedList::deleteNode(int n)
{
	TNODE* pre = head;
	TNODE* node = head->next;
	while (node->id != n) {
		pre = pre->next;
		node = node->next;
		if (node == NULL) {
			cout << "Not found " << n << endl;
			return;
		}
	}
	cout << "delete " << node->id << endl;
	pre->next = node->next;
	delete node;
}

TNODE* MyLinkedList::searchNode(int _id)
{
	TNODE* h = head;
	while (_id != h->id)
		h = h->next;
	return h;
}

void MyLinkedList::display()
{
	TNODE* p = head;
	while (p) {
		cout << p->id << ' ' << p->name << ' ' << p->y << ' ' << p->m << ' ' << p->d << endl;
		p = p->next;
	}
	cout << endl;
}