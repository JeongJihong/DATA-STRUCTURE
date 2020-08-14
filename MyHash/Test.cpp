#include "Hash.h"

int main(void)
{
	MyHash h;

	if (!h.hash_init(10))
		return 1;

	h.hash_insert(10, "全辨悼", 2000, 1, 1);
	h.hash_insert(11, "全老悼", 2000, 1, 1);
	h.hash_insert(12, "全捞悼", 2000, 1, 1);
	h.hash_insert(13, "全伙悼", 2000, 1, 1);
	h.hash_insert(14, "全荤悼", 2000, 1, 1);
	h.hash_insert(15, "全坷悼", 2000, 1, 1);
	h.hash_insert(21, "辫老悼", 2000, 1, 1);
	h.hash_insert(31, "捞老悼", 2000, 1, 1);

	h.hash_display();

	cout << "search node : 15" << endl;
	NODE* t = h.hash_search(17);
	if (t != NULL)	
		h.hash_displaynode(t);
	else			
		cout << "\tnot found node" << endl;

	return 1;
}