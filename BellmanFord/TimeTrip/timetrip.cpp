#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

#define V_MAX 101
#define W_MAX 1001
#define START 0
#define ANDROMEDA 1
#define INF 987654321
#define M 98765432
#define UNREACHABLE 3

vector<pair<int, int> > adj[V_MAX];
bool reachable[V_MAX][V_MAX];

int solve(int v, int sign)
{
	vector<int> upper(v, INF);
	upper[START] = 0;

	// do not touch the original value,
	// it is possible that i and j are directly connected!
	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				reachable[i][j] |= reachable[i][k] && reachable[k][j];


	for (int iter = 0; iter < v-1; iter++) {
		for (int here = 0; here < v; ++here) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second*sign;
				if (upper[there] > upper[here]+cost) {
					upper[there] = upper[here]+cost;
				}
			}
		}
	}

	bool not_pass = true;
	for (int here = 0; here < v; ++here) {
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second*sign;
			if (upper[there] > upper[here]+cost) {
				// cycle!!
				// find whether the edge is connected to the end node.
				if (reachable[here][ANDROMEDA] || reachable[there][ANDROMEDA]) not_pass = false;
			}
		}
	}

	if (upper[ANDROMEDA] >= INF-M) { 
		cout << "UNREACHABLE" << endl;
		return UNREACHABLE;
	}
	else if (!not_pass) cout << "INFINITY";
	else cout << upper[ANDROMEDA]*sign; 

	return 0;
}

int main(void)
{
	int c, v, w;

	cin >> c;
	for (int i = 0; i < c; i++) {
		memset(reachable, false, sizeof(reachable));
		for (int j = 0; j < V_MAX; j++) {
			while (!adj[j].empty()) adj[j].pop_back();
			reachable[j][j] = true;
		}
		cin >> v >> w;
		for (int j = 0; j < w; j++) {
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back(make_pair(b, w));
			reachable[a][b] = true;
		}
	
		int result = solve(v, 1);
		if (result != UNREACHABLE) {
			cout << " ";
			solve(v, -1);
			cout << endl;
		}
	}
	return 0;
}
