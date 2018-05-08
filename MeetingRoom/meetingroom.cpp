#include <iostream>
#include <utility>
#include <vector>
#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

int c;
int n;
int idx;
int sccIdx;
vector<pair<int, int> > meetings;
vector<vector<int> > adj;
vector<int> visited;
vector<int> finished;
vector<int> sccId;

stack<int> sccStck;

bool isDuplicated(int f, int s)
{
	return !(meetings[f].second <= meetings[s].first ||
			meetings[s].second <= meetings[f].first);
}

void makeGraph()
{
	int i, j;
	int size = meetings.size();
	adj.clear();
	adj.resize(size*2);
	for (i = 0; i < size; i+=2) {
		// ai = p
		// ai+1 = !p
		j = i+1;
		adj[i*2+1].push_back(j*2);
		adj[j*2+1].push_back(i*2);
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (isDuplicated(i, j)) {
				//cout << "DUPLICATED:" << i << "," << j <<endl;
				adj[i*2].push_back(j*2+1);
				adj[j*2].push_back(i*2+1);
			}
		}
	}
}

void printGraph()
{
	cout << "PRINTS:" << endl;
	for (int i = 0; i < adj.size(); i++) {
		cout << "[" << i << "]:";
		for (int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

void printMeetings()
{
	for (int i = 0; i < meetings.size(); i++)
		printf("%d %d\n", meetings[i].first, meetings[i].second);
}

int min(int a, int b)
{
	return a > b? b:a;
}

int scc(int here)
{
	int ret, there;

	ret = visited[here] = idx++;
	sccStck.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		there = adj[here][i];
		if (visited[there] == -1)
			ret = min(scc(there), ret);
		else if (finished[there] != 1 && visited[there] < visited[here])
			ret = min(visited[there], ret);
	}

	// if 'here' is the root of scc node,
	// then assign scc index to each node.
	if (ret == visited[here])
	{
		while (true) {
			int top = sccStck.top();
			sccStck.pop();
			sccId[top] = sccIdx;
			finished[top] = 1;
			if (top == here) break;
		}
		sccIdx++;
	}

	return ret;
}

vector<int> tarjanSCC() {
	int ret;
	sccId = visited = finished = vector<int>(adj.size(), -1);
	idx = sccIdx = 0;
	for (int i = 0; i < adj.size(); i++) {
		if (visited[i] == -1) ret = scc(i); 
	}

	return sccId;
}

void showScc() {
	for (int i = 0; i < adj.size(); i++)
		printf("%d ", sccId[i]);
	printf("\n");
	for (int i = 0; i < meetings.size(); i++)
		cout << meetings[i].first << "~" << meetings[i].second << " ";
	cout << endl;
}

vector<int> findTimeSolution() {
	int i;
	int size = adj.size()/2;
	for (i = 0; i < size*2; i+=2)
		if (sccId[i] == sccId[i+1]) {
			cout << "IMPOSSIBLE" << endl;
			return vector<int>();
		}
	
	cout << "POSSIBLE" << endl;
	// PASS IMPOSSIBLE
	vector<pair<int, int> > order;
	for (i = 0; i < size*2; i++) {
	//	if (sccId[i] == 0) {
	//		order.push_back(make_pair(-(sccIdx), i));
	//		continue;
	//	}
			
		order.push_back(make_pair(-sccId[i], i));	
	}
	sort(order.begin(), order.end());

	//for (i = 0; i < adj.size(); i++)
	//	cout << order[i].first << ":" << order[i].second << endl;

	vector<int> results = vector<int>(2*size, -1);
	for (i = 0; i < size*2; i++) {
		int adjIdx = order[i].second;
		
//		cout << order[i].first << ", " << order[i].second << endl;
		int vertIdx = adjIdx / 2; 
		int isNot = adjIdx % 2;
		int isTrue = adjIdx % 2 == 0;
		if (results[vertIdx] == -1) {
			results[vertIdx] = isNot==1?1:0; // reverse! since 
			// first scc node is considered as 'false'
	//		cout << vertIdx << "is set to " << results[vertIdx] << endl;
		} else continue;
	}
	
	return results;
}

int main(void)
{
	int i, j, st_t, end_t;
	cin >> c;
	for (i = 0; i < c; i++) {
		cin >> n;
		meetings.clear();
		idx = 0;
		for (j = 0; j < n*2; j++) {
			cin >> st_t >> end_t;	
			meetings.push_back(make_pair(st_t, end_t));
		}
		
//		printMeetings();
		makeGraph();
		tarjanSCC();
//		showScc();
//		cout << endl;
		vector<int> results = findTimeSolution();
		if (results.size() > 0) {
			for (j = 0; j < n*2; j+=2)
				if (results[j] == 1)
					cout << meetings[j].first << " " << meetings[j].second << endl;
				else
					cout << meetings[j+1].first << " " << meetings[j+1].second << endl;
		}
//		printGraph();
//
//		TODO
//		 we need to find solution
	}

	return 0;

}
