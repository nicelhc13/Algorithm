#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100050
#define INF 9999999

vector<pair<int, int> > adj[MAX];
vector<int> shops;
vector<int> visited(MAX, 0);
vector<vector<int > > adist(30, vector<int >(30, INF));
int dist[MAX];

int* dijkstra(int n, int start) {
	priority_queue<pair<int , int> > pq;
	//vector<int > dist(n, INF);
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < n; i++)
		dist[i] = i==start?0:INF;

	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int here = pq.top().second;
		int  cost = -pq.top().first;
		pq.pop();

		if (cost > dist[here]) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int t_cost = adj[here][i].second+cost;
			if (t_cost >= dist[there]) continue;
			pq.push(make_pair(-t_cost, there));
			dist[there] = t_cost;
		}
	}

	return dist;
}

int dfs(int here, int level, int  dist) {
	int  result = INF;
	if (level == shops.size()) return dist+adist[here][0];	

	for (int i = 0; i < shops.size(); i++) {
		int there = i;
		if (there == here || visited[there] || adist[here][there] == INF) continue;
		visited[there] = 1;
		result = min(result, dfs(there, level+1, adist[here][there]+dist)); 
		visited[there] = 0;
	}

	return result;
}

int main(void)
{
	int c, n, m;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> m;
		for (int j = 0; j < MAX; j++)
			while (!adj[j].empty()) adj[j].pop_back();
		for (int j = 0; j < m; j++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back(make_pair(b, w));
			adj[b].push_back(make_pair(a, w));
		}
		for (int j = 0; j < visited.size(); j++)
			visited[j] = 0;
		for (int j = 0; j < adist.size(); j++)
			for (int k = 0; k < adist[j].size(); k++)
				adist[j][k] = INF; 
		
	
		int s;
		shops.resize(0);
		shops.push_back(0);
		cin >> s;
		for (int j = 0; j < s; j++)
		{
			int sn;
			cin >> sn;
			shops.push_back(sn);
		}

		for (int j = 0; j <= s; j++) {
			//dijkstra(n, shops[j]);
			int* dist = dijkstra(n, shops[j]);
			for (int k = 0; k <= s; k++) {
				adist[j][k] = dist[shops[k]];
			}
		}

		int  result = dfs(0, 0, 0);
		cout << result << endl;
	}
}
