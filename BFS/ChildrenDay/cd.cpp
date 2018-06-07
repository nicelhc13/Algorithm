#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m;
string d;
string c;
vector<int> d_lists;
vector<int> parents;
vector<int> choice;

int append(int here, int x, int mod)
{
	int there = here*10+x;
	if (there >= mod) return mod+there%mod;
	return there%mod;
}

string cd()
{
	queue<int> q;
	q.push(0);
	parents[0] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//for (int i = 0; i < d_lists.size(); i++) {
		//	int there = append(here, d_lists[i], n);
		for (int i = 0; i < d.size(); i++) {
			int there = append(here, d[i]-'0', n);
			if (parents[there] == -1) {
				parents[there] = here;
				choice[there] = d[i]-'0';
				q.push(there);
			}
		}
	}

	if (parents[n+m] == -1) return "IMPOSSIBLE";

	string ret;
	int here = n+m;
	while (parents[here] != here) {
		ret += char(choice[here]+'0');
		here = parents[here];
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> d >> n >> m;

		if (d == "0" && atoi(d.c_str()) == n && n == m) {
			cout << "0" << endl;
			continue;
		}

		//d_lists.resize(0);
		parents = vector<int> (n*2, -1);
		choice = vector<int> (n*2, -1);
		/*
		if (d < 10) d_lists.push_back(d);
		else {
			int tmp = 0;
			while (d>0) {
				tmp=d%10;
				d/=10;	
				d_lists.push_back(tmp);
			}
		}
		*/

//		cout << "==== " << endl;
//		for (int j = 0; j < d.size(); j++)	cout << d[j] << " ";
//		cout << "---- " << endl;
		
		//sort(d_lists.begin(), d_lists.end());
		sort(d.begin(), d.end());
		c = cd();
		cout << c << endl;
	}
	return 0;
}
