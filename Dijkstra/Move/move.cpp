#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define V_MAX 10001
#define INF	987654321

using namespace std;

vector<pair<int, int> > adj[V_MAX];
int dist[V_MAX];

int main(void)
{
	int t, v, e, i, j;
	cin >> t;
	while (t--) {
		cin >> v >> e;

		for (i = 0; i < v; i++) { dist[i] = INF; 
			adj[i].resize(0);
		}

		for (i = 0; i < e; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back(make_pair(b, w));
			adj[b].push_back(make_pair(a, w));
		}

		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, 0));
		dist[0] = 0;
		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[here] < cost) continue;
			for (i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int t_cost = adj[here][i].second+dist[here];
				if (dist[there] > t_cost) {
					pq.push(make_pair(-t_cost, there));
					dist[there] = t_cost;
				}
			}
		}
		cout << dist[v-1] << endl;
	}
}
