#ifndef _MYHASH_H_
#define _MYHASH_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NODE {
public:
	NODE() {
		name = mobile_tel = office_tel = home_tel = e_mail = birth = "", next = NULL;
	}
	string name;
	string mobile_tel;
	string office_tel;
	string home_tel;
	string e_mail;
	string birth;
	NODE* next;
};

class MyHash {
	NODE** bucket;
	int BucketSize;
	int hash_func(string& key);

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
	void hash_displaynode(NODE* t);
	void hash_display();
	NODE* hash_search(string& name);
	void hash_dataload();
	void hash_tockenstring(vector<string>& arr, char* fpln, int len);
	void hash_check(string name);
	void hash_add(string name, string mobile_tel, string office_tel,
		string home_tel, string e_mail, string birth);
	void hash_modify(string key, string mobile_tel, string office_tel,
		string home_tel, string e_mail, string birth);
	void hash_delete(string name);
};

#endif // !_MYCONTACT_H_
