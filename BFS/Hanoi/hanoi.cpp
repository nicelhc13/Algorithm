#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int c, n;
int top[4] = {-1, -1, -1, -1};

bool is_last(vector<vector <int> > status) {
	int i;
	if (status[0].size() != 0 ||
			status[1].size() != 0 || status[2].size() != 0) return false;

	for ( i = 1; i < status[3].size(); i++)
	{
		if (status[3][i] > status[3][i-1]) return false;
	}

	return true;
}

int hanoi(vector<vector<int> > first) {
	map<vector<vector<int> >, int> c;
	queue<vector<vector<int> > > q;

	q.push(first);
	c[first] = 0;

	while (!q.empty()) {
		vector<vector<int> > here = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!here[i].size()) continue;
			//int top = here[i].back();
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				vector<vector<int> > there = here;
				/*
				cout << " 1--" << endl;
				for (int k = 0; k < 4; k++) {
					for (int t = 0; t < there[k].size(); t++)
						cout << there[k][t] << " ";
					cout << endl;
				}
				cout << " 1++" << endl;
				cout << " 2--" << endl;
				*/


				if ((here.size() > j && here[j].size() > 0)
						&& here[j].back() <= here[i].back()) continue;
				//cout << ">>" << there[i].back();
				there[j].push_back(there[i].back());
				//cout << ">>>" << there[i].back();
				there[i].pop_back();
				
				//cout << ">>>" << there[i].back();
				/*
				for (int k = 0; k < 4; k++) {
					for (int t = 0; t < there[k].size(); t++)
						cout << there[k][t] << " ";
					cout << endl;
				}

				cout << " 2++" << endl;
				*/
				if (!c.count(there)) {
					c[there] = c[here]+1;
					if (is_last(there)) { 
						/*
						cout << "0 --" << endl;
						for (int k = 0; k < 4; k++) {
							for (int t = 0; t < there[k].size(); t++)
								cout << there[k][t] << " ";
							cout << endl;
						}
						cout << "0 ++" << endl;
						*/
						return c[there];
					}
					q.push(there);
				}
			}
		}
	}


	return 0;
}

int main(void)
{
	int i,j,k;
	cin >> c;
	for (i = 0; i < c; i++)
	{
		cin >> n;
		vector<vector <int> > first = 
			vector<vector <int> >(4, vector<int>());
		for (j = 0; j < 4; j++) {
			int sn;
			cin >> sn;
			first[j] = vector<int>(sn, 0);
			for (k = 0; k < sn; k++) {
				int tmp;
				cin >> tmp;
				first[j][k] = tmp;
			}
			top[j] = k;
		}

		int result = hanoi(first);

		cout << result << endl;
		/*
		for (j = 0; j < 4; j++) {
			for (k = 0; k < first[j].size(); k++) 
				cout << first[j][k] << " ";
			cout << endl;
		}*/
	}

}
