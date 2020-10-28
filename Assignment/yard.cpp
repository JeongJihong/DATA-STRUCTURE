#include <bits/stdc++.h>
#define MAX_SIZE *max_element(SIZE.begin(), SIZE.end())
#define MIN_SIZE *min_element(SIZE.begin(), SIZE.end())
#define COUNT count( SIZE.begin(), SIZE.end(), MAX_SIZE )
using namespace std;

int N;
vector<stack<int>> YARD;
vector<int> SIZE;

void show_yard(vector<stack<int>> OUT) {
    int i = 0, val;
    stack <int> stemp;

    for (auto w : OUT) {
        stemp = stack<int>();
        cout << ++i << " > ";
        while (!w.empty()) {
            val = w.top();
            stemp.push(val);
            w.pop();
        }
        while (!stemp.empty()) {
            val = stemp.top();
            cout << " " << val;
            stemp.pop();
        }
        cout << "\n";
    }
}

void read_yard() {
    int num, v;
    cin >> N;
    stack<int> s;

    for (int i = 0; i < N; i++) {
        s = stack<int>();
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> v;
            s.push(v);
        }
        YARD.push_back(s);
    }
}

void load_size() {
    SIZE.clear();
    int sz;
    for (int i = 0; i < N; i++) {
        sz = YARD[i].size();
        SIZE.push_back(sz);
    }
}

void move_yard() {
    int max_idx = 0;
    int max_val = 0;
    for (int i = 0; i < N; i++)
        if (MAX_SIZE == YARD[i].size() && max_val < YARD[i].top()) {
            max_val = YARD[i].top();
            max_idx = i;
        }
    YARD[max_idx].pop();

    for (int i = 0; i < N; i++)
        if (MIN_SIZE == YARD[i].size()) {
            YARD[i].push(max_val);
            break;
        }
}

int main() {
    read_yard();
    load_size();
    while (MAX_SIZE - MIN_SIZE > 1) {
        move_yard();
        load_size();
    }
    show_yard(YARD);
    return 0;
}