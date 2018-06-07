#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<vector<char> > mazes;

int try_walking(int x, int y)
{
	if (x == y == dest) return

	vector(pair <int, int>) // 현재 위치에서 갈 수 있는 좌표 목록..
		// maze의 크기를 벗어나면 안됨
		for (a)
				ret += try_walking();

	return ret;
}


int main(void)
{
	while (true) {
		cin >> h >> w;
		if (h == 0 && w == 0)	return 0;
		mazes = vector<vector <char> >(h, vector<char>(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> mazes[i][j]; 

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				cout << mazes[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}

