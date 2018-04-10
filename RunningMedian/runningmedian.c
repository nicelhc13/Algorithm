#include <stdio.h>
#include <string.h>

long long stream[200001];
long long ordered[200001];
int tc;
int n;
int a, b;
long long mid;

void insert(int cur, int cur_idx) {
	int i, j;
	for (i = 0;  i < cur_idx; i++)
		if (cur < ordered[i]) break;

	if (i == cur_idx) {
		ordered[cur_idx] = cur;
		return ;
	}

	for (j = cur_idx; j > i; j--)
		ordered[j] = ordered[j-1];
	ordered[i] = cur;
}

void findRunningMed() {
 	int i, j;
	long long test, cur;
	for (i = 1; i < n; i++) {
		stream[i]  = (stream[i-1]*a+b)%20090711;
		cur = stream[i];
		insert(cur , i);
		
		if (i > 0 && (i-1)%2 == 0) { // even
			mid += ((ordered[i/2] > ordered[(i/2)+1])?ordered[(i/2)+1]:ordered[i/2]);	
		} else { // odd
			mid += (ordered[i/2]);
		}
	}
}

int main(void) {
	int i, j;
	scanf("%d", &tc);

	for (i = 0; i < tc; i++) {
		memset(stream, 0, sizeof(long long)*200001);
		memset(ordered, 0, sizeof(long long)*200001); 
		stream[0] = 1983;
		ordered[0] = 1983;
		mid = 1983;
		scanf("%d %d %d", &n, &a, &b);
		findRunningMed();
		printf("%lld\n", mid%20090711);
	}
	return 0;
}
