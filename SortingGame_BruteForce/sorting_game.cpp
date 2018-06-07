#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int c, n; 
vector<int> unsorted; 
/*

vector<int> reverse(int s, int d, vector<int> unreversed) {
	vector<int> tempVec;

	
	for (int i = d-1; i >= s; i--) {
		tempVec.push_back(unreversed[i]);
	}

	for (int i = s; i < d; i++) {
		unreversed[i] = tempVec[i-s];
	}

	return unreversed;
}
*/
int dfs(vector<int> unsorted, vector<int> solution) {
	int dist = 0;
	map <vector<int>, int> discovered;
	queue<vector<int> > q;
	
	q.push(unsorted);
	discovered[unsorted] = 0;
	while(!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		
		if (here == solution) return discovered[here];
		
		int cost = discovered[here];
		
		
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < n; j++) {
//		for (int i = 0; i < n; i++) {
//			for (int j = i+2; j <= n; j++) {
//				if (j+i <= n) {
					reverse(here.begin()+j, here.begin()+j+i);
					//reverse(i, j, here);
					if (discovered.count(here) == 0) {
						discovered[here] = cost+1;
						q.push(here);
					}
					//reverse(j, j+i, here); // unreverse
					reverse(here.begin()+j, here.begin()+j+i);
					//reverse(i, j, here);
//				}
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = i+2; j <= n; j++) {
				reverse(here.begin()+i, here.begin()+j);
				if (discovered.count(here) == 0) {
					discovered[here] = cost+1;
					q.push(here);
				}
				//reverse(i, j, here);
				reverse(here.begin()+i, here.begin()+j);
			}
		}*/
	}

	return -1;
}

int main()
{
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		unsorted.resize(n);
		for (int j = 0; j < n; j++) cin >> unsorted[j]; 
		vector<int> solution = unsorted;
		sort(solution.begin(), solution.end());
		
		//int result = sorting_game(solution);
		int result = dfs(unsorted, solution);
		cout << result << endl;
	}

	return 0;
}
