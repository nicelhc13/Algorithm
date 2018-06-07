#include <iostream>
#include <vector>

using namespace std;
int M, N;
char t;
vector<vector<vector<int> > > adj;
vector<int> discovered;

void fill_adj(vector<vector <int> > input)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			adj[i][j].push_back(
		}

}

int find_minimal_break(vecotr<vector <int> > input)
{
	fill_adj(input);
}

void main(void)
{
	cin >> M >> N;
	vector<vector <int> > input = 
			vector<vector <int> >(N, vector<int>(M, 0));
	adj = vector<vector <int> >(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> t;
			input[j][i] = t-'0';
		}

	int result = find_minimal_break();
	cout << result << endl;
}
