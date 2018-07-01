#include <iostream>
#include <vector>
#include <queue>

#define MAX_V	1000002
#define INF		1000001
using namespace std;
vector<pair<int, int> > state[MAX_V];
vector<int> fireplace;
vector<int> firestat;

int dijkstra(int start, int v)
{
	priority_queue<pair<int, int> > pq;
	vector<int> dist(MAX_V, INF);
	vector<int> parent(MAX_V, 0);

	pq.push(make_pair(0, start));
	dist[start] = 0;
	parent[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		if (cost > dist[here]) continue;
			
		for (int i = 0; i < state[here].size(); i++) {
			int there = state[here][i].first;
			int t_cost = state[here][i].second+cost; 
			if (t_cost > dist[there]) continue;
			pq.push(make_pair(-t_cost, there));
			dist[there] = t_cost;
			parent[there] = here;
//			cout << there << " is added as " << here << "'s descent" << endl;
		}
	}

	int result = 0;
	for (int i = 0; i < fireplace.size(); i++) {
		result += (dist[fireplace[i]]-1);
		/*
		int t = fireplace[i];
		while (true) {
			int p = parent[t];
			cout << p << " to " << t << endl;
			if (p == 0) break;
			t = p;
		}
		cout << endl;
		*/
	}


	return result;
}

int main(void)
{
	int c, v, e, n, m, a, b, t;

	cin >> c;
	for (int i= 0; i < c; i++) {
		fireplace.resize(0);
		firestat.resize(0);
		for (int j = 0; j < MAX_V; j++)
			state[j].resize(0);
		cin >> v >> e >> n >> m;	
		for (int j = 0; j < e; j++) {
			cin >> a >> b >> t;
			state[a].push_back(make_pair(b, t));
			state[b].push_back(make_pair(a, t));
		}
		for (int j = 0; j < n; j++) {
			int fp; cin >> fp;
			fireplace.push_back(fp);
		}
		for (int j = 0; j < m; j++) {
			int fstt; cin >> fstt;
			firestat.push_back(fstt);
			state[0].push_back(make_pair(fstt, 1));
			//cout << fstt << " is added" << endl;
		}
		int result = dijkstra(0, v);
		cout << result << endl;
		
	}

	return 0;
}
