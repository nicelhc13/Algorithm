#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#include <cmath>

#define MAX_V 30000

using namespace std;

vector<pair<int, double> > adj[MAX_V];

vector<double> dijkstra(int start)
{
	priority_queue<pair<double, int> > pq;
	vector<double> dists(MAX_V, -1);

	pq.push(make_pair(0,start)); 
	dists[start] = 0;
	while(!pq.empty()) {
		int here = pq.top().second;
		double cost = -pq.top().first;
		pq.pop();

		if (dists[here] != -1 && dists[here] < cost) continue;
		
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double next_dist = cost+adj[here][i].second;

			if (next_dist >= dists[there] && dists[there] != -1) continue;
				pq.push(make_pair(-next_dist, there));
				dists[there] = next_dist;
		}

	}

	return dists;
}

int main(void)
{
	int t, n, m;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;		
		for (int j = 0; j < MAX_V; j++) {
			while (!adj[j].empty()) adj[j].pop_back();

		}

		for (int j = 0; j < m; j++) {
			int a, b;
			double w;
			cin >> a >> b >> w; 
			adj[a].push_back(make_pair(b, log(w)));
			adj[b].push_back(make_pair(a, log(w)));
		}
		vector<double> dist = dijkstra(0);
		cout << fixed;
		cout << exp(dist[n-1]) << endl;
		
	}

	return 0;
}
