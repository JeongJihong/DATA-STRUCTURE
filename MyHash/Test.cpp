#include "Hash.h"

int main(void)
{
	MyHash h;

	if (!h.hash_init(10))
		return 1;

	h.hash_insert(10, "ȫ�浿", 2000, 1, 1);
	h.hash_insert(11, "ȫ�ϵ�", 2000, 1, 1);
	h.hash_insert(12, "ȫ�̵�", 2000, 1, 1);
	h.hash_insert(13, "ȫ�ﵿ", 2000, 1, 1);
	h.hash_insert(14, "ȫ�絿", 2000, 1, 1);
	h.hash_insert(15, "ȫ����", 2000, 1, 1);
	h.hash_insert(21, "���ϵ�", 2000, 1, 1);
	h.hash_insert(31, "���ϵ�", 2000, 1, 1);

	h.hash_display();

	cout << "search node : 15" << endl;
	NODE* t = h.hash_search(17);
	if (t != NULL)	
		h.hash_displaynode(t);
	else			
		cout << "\tnot found node" << endl;

	return 1;
}