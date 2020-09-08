#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void moveX(int gap, int& t, pair<int, int> coorin[50], pair<int, int> coorout[5], int i, int& j, int K);
void moveY(int gap, int& t, pair<int, int> coorin[50], pair<int, int> coorout[5], int i, int& j, int K);

int main(int argc, char* argv[])
{
	ifstream infp;
	infp.open("1.txt");

	int K = 0, t[5] = { 0, }, mode = 0;
	pair<int, int> coorin[50], coorout[5];

	//ifstream in;
	//ofstream out("robocop.txt");
	//if (argc < 2)
	//	return -1;

	//infp.open(argv[1]);
	//if (!infp.is_open()) {
	//	cout << "File Not Found" << endl;
	//	return -1;
	//}

	infp >> K;
	for (int i = 0; i < K; ++i)
		infp >> coorin[i].first >> coorin[i].second;
	for (int i = 0; i < 5; ++i)
		infp >> t[i];

	for (int i = 0; i < 5; ++i) {
		int j = 0;
		while (t[i] > 0) {
			if (coorin[j % K].first - coorin[(j + 1) % K].first != 0) { //x좌표가 다르면
				int gap = coorin[(j + 1) % K].first - coorin[j % K].first;
				moveX(gap, t[i], coorin, coorout, i, j, K);
			}
			else { //y좌표가 다르면
				int gap = coorin[(j + 1) % K].second - coorin[j % K].second;
				moveY(gap, t[i], coorin, coorout, i, j, K);
			}
		}
	}

	for (int i = 0; i < 5; ++i)
		cout << coorout[i].first << " " << coorout[i].second << endl;
	infp.close();
	//out.close();

	return 0;
}

void moveX(int gap, int& t, pair<int, int> coorin[50], pair<int, int> coorout[5], int i, int& j, int K)
{
	if (abs(gap) >= t) {
		if (gap > 0) { //오른쪽으로 이동
			coorout[i].first = coorin[j % K].first + t;
			coorout[i].second = coorin[j % K].second;
		}
		else { //왼쪽으로 이동
			coorout[i].first = coorin[j % K].first - t;
			coorout[i].second = coorin[j % K].second;
		}
		t = 0;
	}
	else {
		t -= abs(coorin[j % K].first - coorin[(j + 1) % K].first);
		++j;
	}
}

void moveY(int gap, int& t, pair<int, int> coorin[50], pair<int, int> coorout[5], int i, int& j, int K)
{
	if (abs(gap) >= t) {
		if (gap > 0) { //위쪽으로 이동
			coorout[i].first = coorin[j % K].first;
			coorout[i].second = coorin[j % K].second + t;
		}
		else { //아래쪽으로 이동
			coorout[i].first = coorin[j % K].first;
			coorout[i].second = coorin[j % K].second - t;
		}
		t = 0;
	}
	else {
		t -= abs(coorin[j % K].second - coorin[(j + 1) % K].second);
		++j;
	}
}