#include <iostream>

#define V_MAX 201
#define INF 987654321

using namespace std;

int dist[V_MAX][V_MAX];

void floyd(int v)
{
	for (int k = 0; k < v; k++)
		for (int u = 0; u < v; u++)
			for (int w = 0; w < v; w++)
				if (dist[u][w] > dist[u][k]+dist[k][w])
					dist[u][w] = dist[u][k]+dist[k][w];
}


void update(int u, int k, int w, int v)
{
	dist[u][k] = w;
	dist[k][u] = w;
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
				dist[i][j] = min(dist[i][j], min(dist[i][u]+w+dist[k][j], dist[i][k]+w+dist[u][j]));
}

int main(void)
{
	int t, v, m, n, i, j, k, a, b, w;

	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> v >> m >> n;
		for (j = 0; j < V_MAX; j++) {
			for (k = 0; k < V_MAX; k++)
				dist[j][k] = INF;
			dist[j][j] = 0;
		}

		/*
		for (j = 0; j < v; j++) {
			for (k = 0; k < v; k++)
				cout << dist[j][k] << " ";
			cout << endl;
		}
		*/
				
		for (j = 0; j < m; j++) {
			cin >> a >> b >> w;
			if (dist[a][b] > w) dist[a][b] = w;
			if (dist[b][a] > w) dist[b][a] = w;
		}

		floyd(v);
		int useless = 0;
		for (j = 0; j < n; j++) {
			cin >> a >> b >> w;
			if (dist[a][b] > w) {	
				update(a, b, w, v);
			}
			else useless++;
		}
		cout << useless << endl;
	}
	return 0;
}
