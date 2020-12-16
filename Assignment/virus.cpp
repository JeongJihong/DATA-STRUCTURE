#include <bits/stdc++.h>

using namespace std;

int R, C, k, cnt = 0;

void getInfo(int& R, int& C, int& k, vector<vector<char>>& img)
{
    char tmp;
    vector<char> imgRow;
    vector<int> checkRow;

    cin >> C >> R >> k;
    for (int i = 0; i < R; i++) {       // input 저장
        imgRow.clear();
        for (int j = 0; j < C; j++) {
            cin >> tmp;
            imgRow.push_back(tmp);
        }
        img.push_back(imgRow);
    }
}

void connected(int i, int j, vector<vector<char>>& img)
{
    ++cnt;
    img[i][j] = '?';

    if (j - 1 >= 0 && img[i][j - 1] == '#') { // 좌
        connected(i, j - 1, img);
    }
    if (j + 1 < C && img[i][j + 1] == '#') { // 우
        connected(i, j + 1, img);
    }
    if (i - 1 >= 0 && img[i - 1][j] == '#') { // 상
        connected(i - 1, j, img);
    }
    if (i + 1 < R && img[i + 1][j] == '#') { // 하
        connected(i + 1, j, img);
    }

    return;
}

int main()
{
    int w = 0, msize = 0;
    vector<vector<char>> img;

    getInfo(R, C, k, img);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (img[i][j] == '#') {
                cnt = 0;
                connected(i, j, img);
                if (cnt >= k) {
                    ++w;
                    if (msize < cnt)
                        msize = cnt;
                }
            }
        }
    }

    cout << w << ' ' << msize;
    return 0;
}
