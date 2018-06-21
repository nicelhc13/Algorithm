#include <iostream>
#include <vector>

using namespace std;

int is_possible = 0;
int states[31][12];

int check(int n, int h) {
	for (int i = 1; i <= n; i++) {
		int cur_v = i;
		for (int j = 0; j < h; j++) {
			if (cur_v>0 && states[j][cur_v-1]) cur_v -= 1;
			else if (states[j][cur_v]) cur_v += 1;
			//cout << j << ", " << cur_v << endl;
		}
		if (cur_v == i) continue;
		else return 0;
	}
	
	return 1;
}

void dfs(int max, int cur_cnt, int cur_h, int n, int h) {
	if (max == cur_cnt) {
		if(check(n, h))	is_possible = 1;
		return ;
	}

	for (int i = cur_h; i < h; i++) {
		for (int j = 1; j < n; j++) {
			if (!states[i][j]) { 
				if (!states[i][j-1] && !states[i][j+1]) {
					states[i][j] = 1;
					//cout << i << ", " << j << " is added" << endl;
					dfs(max, cur_cnt+1, i, n, h);
					states[i][j] = 0;
				}
			}
		}
	}

	return ;
}

int main(void)
{
	int n, m, h;
	int a, b;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b; 
		states[a-1][b] = 1;
	}

	/*
	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= n; j++) {
			cout << states[i][j] << " ";
		}
		cout << endl;
	}
	*/

	for (int k = 0; k <= 3; k++) {
		//cout << "k: " << k << endl;
		is_possible = 0;
		dfs(k, 0, 0, n, h);
		if(is_possible) {
			cout << k << endl;
			return 0;
		}
		//cout << "======" << endl;
	}

	cout << "-1" << endl;

	return 0;
}
