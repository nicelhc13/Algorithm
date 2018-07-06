#include <iostream>
#include <vector>
#include <cstring>

#define V_MAX 100
#define INF 987654321

using namespace std;

int adj[V_MAX][V_MAX];
int via[V_MAX][V_MAX];

void floyd(int t) {
	memset(via, -1, sizeof(via));
	for (int k = 0; k < t; k++)
		for (int u = 0; u < t; u++)
			for (int v = 0; v < t; v++)
				if (adj[u][v] > adj[u][k]+adj[k][v]) {
					adj[u][v] = adj[u][k]+adj[k][v];
					via[u][v] = k;
				}
}

void reconstruct(int u, int v, vector<int>& path) {
	if (via[u][v] == -1) {
		path.push_back(u);
		if (u!=v) path.push_back(v);
	} else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}

int main(void)
{
	int n, a, b, w, i, j;
	cin >> n;
	for (i = 0; i < V_MAX; i++)
		for (j = 0; j < V_MAX; j++) adj[i][j] = INF;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b >> w;
		adj[a][b] = w;
		adj[b][a] = w;
	}
	for (i = 0; i < V_MAX; i++)
		adj[i][i] = 0;

	floyd(n);
	vector<int> path;
	reconstruct(1, 3, path);
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << endl;

	return 0;
}
