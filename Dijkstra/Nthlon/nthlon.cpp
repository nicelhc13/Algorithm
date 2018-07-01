#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 987654321
#define MAX_V 410
#define START 201

vector<pair<int, int> > adj;

int customize(int n)
{
	return n+200;
}

void solve(int m) {
	vector<pair<int, int> > graph[MAX_V];

	for (int i = 0; i < m; i++) {
		int a = adj[i].first;
		int b = adj[i].second;
		graph[customize(START)].push_back(make_pair(customize(a-b), a));
	}

	for (int i = -199; i < 200; i++) {
		for (int j = 0; j < m; j++) {
			int a = adj[j].first;
			int b = adj[j].second;
			int delta = a-b+i;
			if (abs(delta) > 200) continue;
			graph[customize(i)].push_back(make_pair(customize(delta), a));
		}
	}

	vector<int> dist(MAX_V, MAX);
	dist[customize(START)] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, customize(START)));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int t_cost = graph[here][i].second+cost;
			if (dist[there] <= t_cost) continue;
			pq.push(make_pair(-t_cost, there)); 
			dist[there] = t_cost;
		}
	}

	if (dist[200]==MAX) cout << "IMPOSSIBLE" << endl; 
	else cout << dist[200] << endl;
}

int main(void)
{
	int c, m;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> m;
		adj.resize(0);

		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			adj.push_back(make_pair(a, b));
		}

		solve(m);
	}

	return 0;
}
