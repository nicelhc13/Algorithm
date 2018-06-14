#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 50

using namespace std;

int h, w;
bool mazes[MAX_SIZE][MAX_SIZE][4];
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int> > visited;

int endian(void)
{
	int i = 0x00000001;
	if ( ((char *)&i)[0])
		return LITTLE_ENDIAN;
	else
		return BIG_ENDIAN;
}

int main(void)
{
	char ch;

	while (true)
	{
		cin >> h >> w;

		if (h == 0 && w == 0) break;

		visited = vector<vector<int> >(h, vector<int>(w, 0));
		queue<int> q;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> ch;
				int p = (isdigit(ch))? (ch-'0'):(10+ch-'A');
				for (int k = 0; k < 4; k++) {
					if ( endian() == BIG_ENDIAN)	mazes[i][j][k] = p & (1 << k);
					else mazes[i][j][3-k] = p & (1 << k);
				}
			}
		
		int start_x = -1;
		int start_y = -1;
		int dir = -1;
		int end_x = -1;
		int end_y = -1;
		for (int i = 0; i < h; i++) {
			if (!mazes[i][0][3]) {
				if (start_x == -1
						&& start_y == -1) {
					start_x = i;
					start_y = 0;
					dir = 3;
				} else {
					end_x = i;
					end_y = 0;
				}
			}

			if (!mazes[i][w-1][1]) {
				if (start_x == -1
						&& start_y == -1) {
					start_x = i;
					start_y = w-1;
					dir = 1;
				} else {
					end_x = i;
					end_y = w-1;
				}
			}
		}

		for (int i = 0; i < w; i++) {
			if (!mazes[0][i][0]) {
				if (start_x == -1 &&
						start_y == -1) {
					start_x = 0;
					start_y = i;
					dir = 0;
				} else {
					end_x = 0;
					end_y = i;
				}
			}

			if (!mazes[h-1][i][2]) {
				if (start_x == -1 &&
						start_y == -1) {
					start_x = h-1;
					start_y = i;
					dir = 2;
				} else {
					end_x = h-1;
					end_y = i;
				}
			}
		}

//		cout << "start x:" << start_x << ", start y:" <<start_y << endl;
//		cout << "end x:" << end_x << ", end y:" <<end_y << endl;
//		cout << endl;

		q.push(start_x);
		q.push(start_y);
		q.push(dir);
		visited[start_x][start_y]++;

		while (!q.empty()) {
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			int from = q.front(); q.pop();

			for (int k = 0; k < 4; k++)
			{
				if (!mazes[x][y][k]) {
					int mx = x+mv[k][0];
					int my = y+mv[k][1];
					if (k == from || mx < 0 || mx >= h || my < 0 || my >= w) continue;
					visited[mx][my]++;
					//cout << x << "," << y << " and direction is " << k << endl;
					//cout << mx << "," << my << endl;
					if (visited[mx][my]>1) continue;
					q.push(mx);
					q.push(my);
					q.push((k < 2)? (k+2):(k-2));
				}
			}
		}

		//cout << visited[end_x][end_y] << endl;
		if (!visited[end_x][end_y]) {
			cout << "NO SOLUTION" << endl;
			continue;
		}

		int i, j, is_multiple = 0;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				//cout << i << ", " << j << endl;
				if (!visited[i][j]) {
					cout << "UNREACHABLE CELL" << endl;
					break;
				}
				if (visited[i][j] > 1) {
					is_multiple = 1;
				}
			}
			if (j != w) break;
		}
	
		if (i != h) {
			continue;
		}

		if (is_multiple) { 
			cout << "MULTIPLE PATHS" << endl;
			continue;
		}
		cout << "MAZE OK" << endl;
	}


	return 0;
}

