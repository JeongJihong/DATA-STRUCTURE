#ifndef _HASH_H
#define _HASH_H
#include <iostream>
#include <string>

using namespace std;

typedef struct _node
{
    int id;
    string name;
    int year, month, day;
    struct _node *next;
} NODE;

class MyHash {
    NODE** bucket;
    int BucketSize;
    int hash_func(int key);
public:
    MyHash() {
        bucket = nullptr;
        BucketSize = 0;
    }
    ~MyHash() {
        hash_deleteall();
    }
    NODE** hash_init(int size);
    void hash_deleteall();
    void hash_insert(int _id, string _name, int y, int m, int d);
    void hash_displaynode(NODE* t);
    void hash_display();
    NODE* hash_search(int id);
};

#endif