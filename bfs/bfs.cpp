#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector <int> > adj(10, vector<int>(10));

vector<int> bfs(int start) {
	vector<bool> isDiscovered(adj.size(), false);
	queue<int> q;
	vector<int> order;

	isDiscovered[start] = true;
	q.push(start);

	while(!q.empty()) {
		int point = q.front();
		q.pop();
		order.push_back(point);
		
		for (int i = 0; i < adj[point].size(); i++) {
				int there = adj[point][i];
				if (isDiscovered[there] == false) {
					isDiscovered[there] = true;
					q.push(there);
				}
		}
	}

	return order;
}

int main()
{
//	adj.resize(10);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[3].push_back(5);
	adj[3].push_back(6);
	vector<int> order = bfs(1);

	for (int i = 0; i < order.size(); i++) {
 		int order_item = order[i];
		cout << order_item << endl;
	}
}


