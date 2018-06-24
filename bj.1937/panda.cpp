#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int> > m(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			m[i][j] = a;	
		}

	return 0;
}
