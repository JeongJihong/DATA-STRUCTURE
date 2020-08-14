#include "MyHash.h"

int MyHash::hash_func(string& key)
{
    const char* ch = key.c_str();
    unsigned int sum = 0;
    for (unsigned int i = 0; i < key.size(); i++)
    {
        sum += ch[i];
    }

    int h = sum % BucketSize;
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

void MyHash::hash_displaynode(NODE* t)
{
    cout << '\t' << t->name << ", " << t->mobile_tel << ", " << t->office_tel << ", " << t->home_tel<< ", " << t->e_mail << ", " << t->birth << endl;
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
    cout << "------------------------------------------------------------------------------------" << endl;
}

NODE* MyHash::hash_search(string& name)
{
    int h = hash_func(name);

    NODE* t = bucket[h];
    while (t != NULL)
    {
        if (t->name == name)
            return t;
            
        t = t->next;
    }
    return NULL;
}

void MyHash::hash_dataload()
{
    int cnt = 0;
	FILE* fp;
	errno_t err = fopen_s(&fp, "contact.txt", "rt");
	if (err != 0)
	{
		cout << "Fail to open file!";
		return;
	}

    vector<string> vec;
	char fpln[64];
	while (fgets(fpln, 64, fp) != NULL)
	{
		int len = strlen(fpln);
		if (fpln[len - 1] == '\n')
			fpln[len - 1] = '\0';

        hash_tockenstring(vec, fpln, len);
        hash_add(vec[cnt], vec[cnt + 1], vec[cnt + 2], vec[cnt + 3], vec[cnt + 4], vec[cnt + 5]);
        cnt += 6;
	}
	fclose(fp);
}

void MyHash::hash_tockenstring(vector<string>& arr, char* fpln, int len)
{
    int cnt = 0;
	string t = "";
	for (int i = 0; i < len; i++)
	{
		if (fpln[i] == ',')
		{
			arr.push_back(t);
			t = "";
			continue;
		}
		t += fpln[i];
	}
    arr.push_back(t);
}

void MyHash::hash_check(string name)
{
    NODE* t = hash_search(name);
    if (t == NULL) {
        cout << "Not Found" << endl;
        return;
    }
    hash_displaynode(t);
}

void MyHash::hash_add(string name, string mobile_tel, string office_tel,
    string home_tel, string e_mail, string birth)
{
    NODE* t = new NODE;
    t->name = name;
    t->mobile_tel = mobile_tel;
    t->office_tel = office_tel;
    t->home_tel = home_tel;
    t->e_mail = e_mail;
    t->birth = birth;

    int h = hash_func(name);

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

void MyHash::hash_modify(string key, string mobile_tel, string office_tel,
    string home_tel, string e_mail, string birth)
{
    NODE* t = hash_search(key);
    t->mobile_tel = mobile_tel;
    t->office_tel = office_tel;
    t->home_tel = home_tel;
    t->e_mail = e_mail;
    t->birth = birth;
}

void MyHash::hash_delete(string name)
{
    int h = hash_func(name);

    NODE* t = bucket[h];
    while (t != NULL)
    {
        NODE* n = t->next;
        if (t->name == name) {      //첫번째 node 삭제
            bucket[h] = t->next;
            delete t;
            return;
        }
        while (n != NULL && n->name != name) {
            t = t->next;
            n = n->next;
            if (n == NULL) {
                cout << "Not Found" << endl;
                return;
            }
        }
        if (n == NULL) {      //마지막 node 삭제
            t->next = NULL;
            delete n;
            return;
        }

        t->next = n->next;
        delete n;
    }
}