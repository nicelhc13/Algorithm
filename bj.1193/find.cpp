#include <iostream>

using namespace std;

#define MAX	10000000

int main(void)
{
	int x, k = 1;

	cin >> x;

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j <= i; j++, k++) {
			if (k == x) {
				if (i%2) {
					cout << (i-j+1) << "/" << j << endl;	
				} else {
					cout << j << "/" << (i-j+1) << endl; 
				}
				return 0;
			}
		}
	}

	return 0;
}
