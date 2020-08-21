#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;
	ofstream fout("bitmap.txt");
	long long num = 0;
	long long bmap[64] = { 0, };
	long long tmap[64] = { 0, };
	
	if (argc < 2)
		return -1;

	fin.open(argv[1]);
	if (!fin.is_open()) {
		cout << "File Not Found" << endl;
		return -1;
	}
	
	for (int i = 0; i < 64; ++i) {
		fin >> num;
		bmap[i] = num;
	}
	
	for (int i = 0; i < 64; ++i) {
		for (int j = 63; j >= 0; --j) {
			tmap[63 - j] |= ((bmap[i] >> j) & 1) << (63 - i);
		}
	}

	for (int i = 0; i < 64; ++i) {
		cout << tmap[i] << endl;
		fout << tmap[i] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
