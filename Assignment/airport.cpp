#include <bits/stdc++.h>

using namespace std;

void getInfo(int& airstripNum, vector<queue<int>>& airstrip, queue<int>& singleAirstrip)
{
	
	cin >> airstripNum;
	for (int i = 0; i < airstripNum; i++) {
		int airplane;
		while (cin >> airplane && airplane != 0)
			singleAirstrip.push(airplane);
		airstrip.push_back(singleAirstrip);
		singleAirstrip = queue<int>();	//queue 초기화
	}
}

void priorPrint(int airstripNum, vector<queue<int>>& airstrip, queue<int>& singleAirstrip)
{
	while (1) {
		int minAirplane = 10001, minIdx = 0;
		for (int i = 0; i < airstripNum; i++) {		//우선순위 높은 비행기 찾기
			if (!airstrip[i].empty()) {		//활주로가 비어있지 않으면
				if (minAirplane > airstrip[i].front()) {
					minAirplane = airstrip[i].front();
					minIdx = i;
				}
			}
		}
		cout << airstrip[minIdx].front() << endl;
		airstrip[minIdx].pop();

		int emptyCnt = 0;		//모든 활주로가 비어있으면
		for (int i = 0; i < airstripNum; i++) {
			if (airstrip[i].empty())
				emptyCnt++;
		}
		if (emptyCnt == airstripNum)
			break;
	}
}

int main()
{
	int airstripNum;
	vector<queue<int>> airstrip;
	queue<int> singleAirstrip;

	getInfo(airstripNum, airstrip, singleAirstrip);
	priorPrint(airstripNum, airstrip, singleAirstrip);

	return 0;
}