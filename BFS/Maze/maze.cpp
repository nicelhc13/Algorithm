#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;
typedef pair<int, int> d_int;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int maze_runner(vector<vector<int> > maze, int n, int m)
{
	queue<d_int > q;
	map<d_int, int> c;

	q.push(make_pair(0, 0));
	c[make_pair(0, 0)] = 1;

	while(!q.empty()) {
		d_int coord = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx= coord.first+dir[i][0];
			int ny = coord.second+dir[i][1];
			if (nx < 0 || nx > n-1 
					|| ny < 0 || ny > m-1 
					|| c.count(make_pair(nx, ny)) != 0
					|| !maze[nx][ny]) continue; 
			q.push(make_pair(nx, ny));
			c[make_pair(nx, ny)] = c[make_pair(coord.first, coord.second)]+1;
			if (nx == n-1 && ny == m-1) return c[make_pair(nx, ny)];
		}
	}

	return -1;
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	vector<vector<int> > maze=
		vector<vector<int> >(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char t;
			cin >> t;
			maze[i][j] = t-'0';
		}
	}
	int result = maze_runner(maze, n, m);
	cout << result << endl;

	return 0;
}
