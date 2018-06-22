#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int arr[10][10];
int dist[10];

void dijkstra()
{
	priority_queue<pair<int, int> > pq;

	dist[0]= 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		int i;

		if (dist[here] < cost) continue;

		for (int there = 0; there < 10; there++) {
			if (there == here || arr[here][there] < 1) continue;
			int cur_cost = cost+arr[here][there];
			if (dist[there] > 0 && (dist[there] < cur_cost))
				continue;
			pq.push(make_pair(cur_cost, there));
			dist[there] = cur_cost; 
		}
	}


	for (int i = 0; i < 10; i++) {
		cout << dist[i] << " ";
	}

}

int main(void)
{
	for (int i = 0; i < 4; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << a <<"," << b << "," << c << endl;
		arr[a][b] = c;
	}

	dijkstra();
//	cout << dijkstra() << endl;
	
	return 0;
}
