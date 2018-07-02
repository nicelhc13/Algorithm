#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define V_MAX 20000
#define INF 999999
using namespace std;

int v, e, k;
vector<pair<int, int> > adj[V_MAX+1];
int dist[V_MAX+1];

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	for (int i = 1; i <= v; i++) dist[i] = INF;
	dist[start] = 0;	
	pq.push(make_pair(0, start));
	while(!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int t_cost = adj[here][i].second+cost;
			if (dist[there] > t_cost) {
				dist[there] = t_cost;
				pq.push(make_pair(-t_cost, there));
			}
		}
	}
}

int main(void)
{
	cin >> v >> e >> k;
	int a, b, w;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));
	}
	dijkstra(k);
	for (int i = 1; i <= v; i ++)
		if (dist[i] != INF) cout << dist[i] << endl;
		else cout << "INF" << endl;
	return 0;
}

