#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> i, pair<int, int> j)
{
    return i.second > j.second;
}

int main(int argc, char* argv[])
{
    int fun_num = 0, num = 0, k = 0, cnt = 0;
    pair<int, int> p;
    vector<pair<int, int>> v;

    ifstream in;
    ofstream out("polyadd.txt");
    
    in >> fun_num;
    for (int i = 0; i < fun_num; ++i) {
        in >> num;
        for (int j = 0; j < num; ++j) {
            in >> p.first >> p.second;
            for (k = 0; k < v.size(); ++k) {
                if (v[k].second == p.second) {
                    v[k].first += p.first;
                    break;
                }
            }
            if(k == v.size())
                v.push_back(p);
        }
    }
    sort(v.begin(), v.end(), compare); //desc sort
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first != 0)
            ++cnt;
    }
    out << cnt << endl;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first != 0)
            out << v[i].first << " " << v[i].second << endl;
    }
    in.close();
    out.close();

    return 0;
}