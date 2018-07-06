#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>

#define V_MAX 510 
#define INF 987654321

using namespace std;

int dist[V_MAX][V_MAX];
int W[V_MAX][V_MAX];
int delay[V_MAX];

void floyd2(int v)
{
	vector<pair<int, int> > ordered;
	for (int i = 1; i <= v; i++) {
		ordered.push_back(make_pair(delay[i], i));
	}
	sort(ordered.begin(), ordered.end());

	for (int k = 0; k < v; k++) {
		int d = ordered[k].first;
		int p = ordered[k].second;
		for (int u = 1; u <= v; u++)
			for (int w = 1; w <= v; w++)
				if (dist[u][w] > dist[u][p]+dist[p][w]) {
					dist[u][w] = dist[u][p]+dist[p][w];
					W[u][w] = min(W[u][w], dist[u][p]+dist[p][w]+d);
				}
	}
}

int min(int a, int b)
{
	return a>b?b:a;
}

int main(void)
{
	int v, e, a, b, w, t, s, d, i, j;
	cin >> v >> e;
	for (i = 0; i < V_MAX; i++)
		for (j = 0; j < V_MAX; j++) {
			if (i==j) {
				dist[i][j] = 0;
				W[i][j] = 0;
			} else {
				dist[i][j] = INF;
				W[i][j] = INF;
			}
		}

	for (i = 1; i <= v; i++) {
		int dl;
		cin >> dl;
		delay[i] = dl;
	}

	for (i = 0; i < e; i++) {
		cin >> a >> b >> w;
		dist[a][b] = w;
		dist[b][a] = w;
		W[a][b] = w;
		W[b][a] = w;
	}
	floyd2(v);
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> s >> d;
		cout << W[s][d] << endl; 
	}
	return 0;
}
