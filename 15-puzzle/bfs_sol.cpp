#include <iostream>
#include <vector>
using namespace std;

class State {
	vector<State> getAdjacent() const;
	bool operator < (const State& rhs) const;
	bool operator == (const State& rhs) const;
}


typedef map<State, int> StateMap;

int bfs(State start, State finish) {
	if (start == finish) return 0;

	StateMap c;
	queue<State> q;
	c[start] = 0;

	while(!q.empty()) {
		State here = q.front();
		q.pop();
		int cost = c[here];

		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); i++) {
			if (c.count(adjacent[i]) == 0) {
				if (adjacent[i] == finish) return cost+1;
				c[adjacent] = cost+1;
				q.push(adjacent[i]);
			}
		}

	}

}

int main(void)
{

}
