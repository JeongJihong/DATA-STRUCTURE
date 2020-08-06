#include "MyDoubleLinkedList.h"

MyDoubleLinkedList::~MyDoubleLinkedList()
{
	DNODE* p = head;
	while (p) {
		cout << "delete " << p->id << endl;
		p = p->next;
		delete p->prev;
	}
}

void MyDoubleLinkedList::addNodeBack(DNODE* node)
{
	DNODE* pre = head;
	if (pre == NULL) {
		head = node;
		return;
	}
	DNODE* h = head->next;
	while (h) {
		h = h->next;
		pre = pre->next;
	}
	h = node;
	h->prev = pre;
	pre->next = h;
}

void MyDoubleLinkedList::addNodeBack(int _id, string _name, int _y, int _m, int _d)
{
	DNODE* node = new DNODE;

	node->id = _id;
	node->name = _name;
	node->y = _y;
	node->m = _m;
	node->d = _d;
	node->next = NULL;
	node->prev = NULL;
	addNodeBack(node);
}

void MyDoubleLinkedList::addNodeFront(DNODE* node)
{
	if (head == NULL){
		head = node;
		return;
	}
	head->prev = node;
	node->next = head;
	head = node; 
}

void MyDoubleLinkedList::addNodeFront(int _id, string _name, int _y, int _m, int _d)
{
	DNODE* node = new DNODE;

	node->id = _id;
	node->name = _name;
	node->y = _y;
	node->m = _m;
	node->d = _d;
	node->next = NULL;
	node->prev = NULL;
	addNodeFront(node);
}

DNODE* MyDoubleLinkedList::searchNode(int _id)
{
	DNODE* p = head;
	while (p->id != _id) p = p->next;
	return p;
}

void MyDoubleLinkedList::insertNode(int _id, int myid, string _name, int _y, int _m, int _d)
{
	DNODE* node = new DNODE;
	node->id = myid;
	node->name = _name;
	node->y = _y;
	node->m = _m;
	node->d = _d;
	node->next = NULL;
	node->prev = NULL;
	insertNode(searchNode(_id), node);
}

void MyDoubleLinkedList::insertNode(DNODE* _node, DNODE* node)
{
	node->next = _node->next;
	node->next->prev = node;
	_node->next = node;
	node->prev = _node;
}

void MyDoubleLinkedList::deleteNode(int n)
{
	DNODE* before = head;
	DNODE* present = head->next;

	if (before->id == n) {		//삭제하는 노드가 head일 경우
		cout << "delete " << before->id << endl;
		head = before->next;
		head->prev = NULL;
		delete before;
		return;
	}

	while (present->id != n) {
		before = before->next;
		present = present->next;
		if (present == NULL) {
			cout << "Not Found " << n << endl;
			return;
		}
	}

	if (present->next == NULL) {		//삭제하는 노드가 마지막 노드일 경우
		cout << "delete " << present->id << endl;
		present->prev->next = NULL;
		delete present;
		return;
	}

	cout << "delete " << present->id << endl;
	before->next = present->next;
	present->next->prev = before;
	delete present;
}

void MyDoubleLinkedList::displayFoward()
{
	DNODE* h = head;
	while (h->next) h = h->next; //가장 뒤로 이동

	while (h) {
		cout << h->id << ' ' << h->name << ' ' << h->y << ' ' << h->m << ' ' << h->d << endl;
		h = h->prev;
	}
	cout << endl;
}

void MyDoubleLinkedList::displayBackward()
{
	DNODE* h = head;
	while (h) {
		cout << h->id << ' ' << h->name << ' ' << h->y << ' ' << h->m << ' ' << h->d << endl;
		h = h->next;
	}
	cout << endl;
}