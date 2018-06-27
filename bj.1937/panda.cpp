#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > mm;
vector<vector<int> > m;;
int longest = 1;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solv(int x, int y, int n) {
	if (mm[x][y] > 0) return mm[x][y];

	for (int i = 0; i < 4; i++) {	
		int mx = x+dir[i][0];
		int my = y+dir[i][1];
		if (mx < 0 || mx > n-1 || my < 0 || my > n-1 ||
				m[x][y] >= m[mx][my]) continue;
		mm[x][y] = max(solv(mx, my, n)+1, mm[x][y]);
		if (mm[x][y] > longest) longest = mm[x][y];
	}

	if (!mm[x][y]) mm[x][y] = 1;

	return mm[x][y];
}

int main(void)
{
	int n;
	cin >> n;
	m = vector<vector<int> >(n, vector<int>(n, 0));
	mm = vector<vector<int> >(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			m[i][j] = a;	
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			solv(i, j, n); 
	cout << longest << endl;


	return 0;
}
