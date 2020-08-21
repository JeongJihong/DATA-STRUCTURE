#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
		return -1;
	
	ifstream in;
	ofstream out;
	long long num = 0;
	long long bmap[64] = { 0, };
	long long tmap[64] = { 0, };
	
	in.open(argv[1])
	if (!in.is_open()) {
		cout << "File Not Found" << endl;
		return -1;
	}
	
	for (int i = 0; i < 64; ++i) {
		in >> num;
		bmap[i] = num;
	}
	
	for (int i = 0; i < 64; ++i) {
		for (int j = 63; j >= 0; --j) {
			tmap[63 - j] |= ((bmap[i] >> j) & 1) << (63 - i);
		}
	}

	for (int i = 0; i < 64; ++i)
		out << tmap[i] << endl;

	in.close();
	out.close();
	return 0;
}
