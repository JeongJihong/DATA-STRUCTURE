#include "Hash.h"

int MyHash::hash_func(int key)
{
    int h = key % BucketSize;
    return h;
}

NODE** MyHash::hash_init(int size)
{
    BucketSize = size;
    bucket = (NODE**)malloc(sizeof(NODE*) * BucketSize);

    if (bucket == NULL)
    {
        printf("memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < BucketSize; i++)
        bucket[i] = NULL;
    return bucket;
}

void MyHash::hash_deleteall()
{
    NODE* t, * p;
    for (int i = 0; i < BucketSize; i++)
	{
        t = bucket[i];
        while (t != NULL)
        {
	        p = t;
	        t = t->next;
	        delete p;
        }
	}

    free(bucket);
}

void MyHash::hash_insert(int _id, string _name, int y, int m, int d)
{
    NODE* t = new NODE;// (NODE*)malloc(sizeof(NODE));
    t->id = _id;
    t->name = _name;
    t->year = y;
    t->month = m;
    t->day = d;
    t->next = NULL;

    int h = hash_func(t->id);

    if (bucket[h] == NULL)
        bucket[h] = t;
    else
    {
        NODE* n = bucket[h];
        while (n->next != NULL)
            n = n->next;

        n->next = t;
    }
}

void MyHash::hash_displaynode(NODE* t)
{
    cout << '\t' << t->id << ", " << t->name << ", " << t->year << '-' << t->month << '-' << t->day << endl;
}

void MyHash::hash_display()
{
    for (int i = 0; i < BucketSize; i++)
    {
        printf("Bucket %d\n", i);
        NODE* t = bucket[i];
        while (t != NULL)
        {
            hash_displaynode(t);
            t = t->next;
        }
    }
}

NODE* MyHash::hash_search(int id)
{
    int h = hash_func(id);

    NODE* t = bucket[h];
    while (t != NULL)
    {
        if (t->id == id)
            return t;
        t = t->next;
    }
    return NULL;
}
