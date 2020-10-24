#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int N, x, y;
	tuple<int, int, int> t, tmp;
	vector<tuple<int, int, int>> v;
	vector<int> vi;
	stack<tuple<int, int, int>> s;

	cin >> N;
	for (int i = 0; i < N; i++) {	// input�޾Ƽ� tuple�� vector�� ����
		cin >> x >> y;
		t = make_tuple(i + 1, x, y);
		v.push_back(t);
	}

	for (int i = 0; i < N - 1; i++) { //���� (x�� �۰� y�� ū ������)
		for (int j = i + 1; j < N; j++) {
			if (get<1>(v[i]) >= get<1>(v[j])) { //x�� ũ�ų� ������
				if (get<1>(v[i]) == get<1>(v[j]) && get<2>(v[i]) > get<2>(v[j])); //x�� ���� ��� + y�� ũ��
				else {
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
	}

	s.push(v[0]); //stack�� vector�� ù��° ���� �ְ� ����
	for (int i = 1; i < N; i++) {
		while (get<1>(v[i]) >= get<1>(s.top()) && get<2>(v[i]) <= get<2>(s.top())) {
			s.pop();
			if (s.empty())
				break;
		}
		s.push(v[i]);
	}

	int size = s.size();
	for (int i = 0; i < size; ++i) {
		vi.push_back(get<0>(s.top()));
		s.pop();
	}

	sort(vi.begin(), vi.end());

	for (int i = 0; i < size; ++i) {
		cout << vi[i] << endl;
	}

	return 0;
}