#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define V_MAX 1001
#define INF	999999999

using namespace std;

vector<pair<int, int> > adj[V_MAX];

int dist[V_MAX] = {0};

void dijkstra(int s, int e)
{
	priority_queue<pair<int, int> > pq;
	dist[s] = 0; pq.push(make_pair(0, s));
	while(!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first; pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int before = dist[there];
			int after = dist[here]+adj[here][i].second;
			if (after < before) {
				dist[there]=after;
				pq.push(make_pair(-after,there)); 
			}
		}
	}
	//for(int i = 0; i <= 5; i++) cout << dist[i] << endl; 
	cout << dist[e] << endl;
	
}

int main(void)
{
	int n, m, a, b, w, start, dest;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dist[i] = INF; 
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));		
	}
	cin >> start >> dest;
	dijkstra(start, dest);

	return 0;
}
