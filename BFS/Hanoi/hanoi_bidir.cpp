#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int c[1<<(24)];

int set(int _stat, int _idx, int _r) {
	return (_stat & ~(3 << (_idx*2))) |
			(_r << (_idx*2));
}

int get(int _stat, int _idx) {
	return (_stat >> (_idx*2)) & 3; 
}

int sgn(int x) {if(!x) return 0; return x > 0? 1:-1;}
int incr(int x) { if (x<0) return x-1; return x+1;}


int hanoi(int start, int finish, int n)
{
	if (start == finish) return 0;
	queue<int> q;
	memset(c, 0, sizeof(c));
	//cout << bitset<16>(start) << endl;
	//cout << bitset<16>(finish) << endl;

	q.push(start);
	c[start] = 1;
	q.push(finish);
	c[finish] = -1;
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		int top[4] = {-1, -1, -1, -1};
		for (int i = n-1; i >= 0; i--) {
			top[get(here, i)] = i;
		}

		for (int i = 0; i < 4; i++) {
			if (top[i] == -1) continue;
			for (int j = 0; j < 4; j++) {
				if (i == j || (top[j] < top[i] && top[j] != -1)) continue;
				//cout << "ring " << i << " to " << j << endl;
				//cout << "disc " << top[i] << " is moved" << endl;
				//cout << bitset<16>(here) << endl;
				int there = set(here, top[i], j);
				if (c[there] == 0) {
					c[there] = incr(c[here]);
					q.push(there);
				}
				else if (sgn(c[there]) != sgn(c[here]))
					return abs(c[there]) + abs(c[here]) - 1;
			}
		}
	}

	return -1;
}


int main(void)
{
	int c, n;
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		int stat = 0, finish = 0;
		for (int j = 0; j < 4; j++) {
			int sn;
			cin >> sn;
			for (int k = 0; k < sn; k++) {
				int tv;
				cin >> tv;
				stat = set(stat, tv-1, j);
			}
		}

		for (int j = 0; j < n; j++)
			finish = set(finish, j, 3);

		cout << hanoi(stat, finish, n) << endl;
	}

	return 0;
}
