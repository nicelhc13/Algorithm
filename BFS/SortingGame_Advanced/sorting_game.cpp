#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int c, n; 
vector<int> unsorted; 
map<vector<int>, int> dist;

void precalc(int _n) {
	vector<int> pre_vec(_n);
	queue<vector<int> > q;

	for (int i = 0; i < _n; i++) {
		pre_vec[i] = i;
	}

	q.push(pre_vec);
	dist[pre_vec] = 0;

	while (!q.empty()) {
//:		cout << q.size() << endl;
		vector<int> here = q.front();

		q.pop();
		int cost = dist[here];
		for (int i = 0; i < _n; i++) {
			for (int j = i+2; j <= _n; j++) {
				reverse(here.begin()+i, here.begin()+j);
				if (dist.count(here) == 0) {
					dist[here] = cost+1;
					q.push(here);

//					for (int k = 0; k < _n; k++)
//						cout << here[k] << " ";
//					cout << endl;
				}

				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}
}

int solve(vector<int> unsorted) {
	vector<int> sorted(unsorted.size(), 0);
	for (int i = 0; i < unsorted.size(); i++) {
		int item_idx = 0;
		for (int j = 0; j < unsorted.size(); j++) {
			if (unsorted[i] > unsorted[j]) {
				item_idx++;
			}
		}
		sorted[i] = item_idx;
	}

	return dist[sorted];
}

int main()
{
	cin >> c;
	for (int i = 1; i <= 8; i++)
	{
		precalc(i);
	}
	for (int i = 0; i < c; i++) {
		cin >> n;
		unsorted.resize(n);
		for (int j = 0; j < n; j++) cin >> unsorted[j]; 
		vector<int> solution = unsorted;
		sort(solution.begin(), solution.end());
		
		//precalc(n);
		int result = solve(unsorted);
		cout << result << endl;

	}

	return 0;
}
