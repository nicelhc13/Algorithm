#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<pair<int, int> > outedge;
vector<vector<char> > mazes;

string hexTobin(char c)
{
	switch(c)
	{
		case 'A':
			return "1010";
		case 'B':
			return "1011";
		case 'C':
			return "1100";
		case 'D':
			return "1101";
		case 'E':
			return "1110";
		case 'F':
			return "1111";
		case '0':
			return "0000";
		case '1':
			return "0001";
		case '2':
			return "0010";
		case '3':
			return "0011";
		case '4':
			return "0100";
		case '5':
			return "0101";
		case '6':
			return "0110";
		case '7':
			return "0111";
		case '8': 
			return "1000";
		case '9':
			return "1001";
		default:
			return "fail";
	}
}

int calc_out(int x, int y, int val)
{
	string bin = hexTobin(val);
	if (x == h-1 && y == w-1) { // n, n
		if (bin[1] == '0' || bin[2] == '0') return 1;
	}  else if (0 < x && x < h && y == w-1) { // n-x, n
		if (bin[1] == '0') return 1;
	} else if (x == h-1 && 0 < y && y < w) { // n, n-x
		if (bin[2] == '0') return 1;
	} else if (x == 0 && y == 0) { // 0, 0
		// 0 x x 0
		if (bin[0] == '0' || bin[3] == '0') return 1;
	} else if (x == 0 && y == w-1) { // 0, n
		if (bin[0] == '0' || bin[1] == '0') return 1;
	} else if (x == h-1 && y == 0) { // n, 0
		if (bin[2] == '0' || bin[3] == '0') return 1;
	} else if (0 < x && x < h && y == 0) { // n-x, 0
		if (bin[3] == '0') return 1;
	} else if (x == 0 && 0 < y && y < w) { // 0, n-y
		if (bin[0] == '0') return 1;
	}	

	return 0;
}

/*
int try_walking(int x, int y)
{
	if (x == y == dest) return

	vector(pair <int, int>) // 현재 위치에서 갈 수 있는 좌표 목록..
		// maze의 크기를 벗어나면 안됨
		for (a)
				ret += try_walking();

	return ret;
}*/


int main(void)
{
	while (true) {
		cin >> h >> w;
		if (h == 0 && w == 0)	return 0;
		mazes = vector<vector <char> >(h, vector<char>(w, 0));
		outedge.resize(0);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				std::cin >> std::hex >> mazes[i][j]; 
				if (calc_out(i, j, mazes[i][j])) {
					outedge.push_back(make_pair(i, j));
					cout << "added:" << mazes[i][j] << endl;
				}
			}
		}

		cout << "FINISH====" << endl;
	}
	return 0;
}

