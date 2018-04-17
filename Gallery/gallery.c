#include <stdio.h>
#include <string.h>

#define MAX		1000

int c, g, h, tg1, tg2;
int gallery[MAX][MAX];
int isVisited[MAX];
int marked[MAX];

int dfs(int here)
{
	int i, result = 0;
	int isLeaf = 1;
	int isNeedToMark = 0;
	isVisited[here] = 1;
	
	for (i = 0; i < g; i++)
		if (gallery[here][i] && !isVisited[i]) {
			result += dfs(i);
			isLeaf = 0;
			if (marked[i] == 0)	isNeedToMark = 1; 
		}
	
	if (isLeaf)	return 0;

	if (isNeedToMark) {
		result++;
		marked[here] = 1;
		for (i = 0; i < g; i++)
			if (gallery[here][i] || 
				gallery[i][here] ) marked[i] = 1;
	}
	return result;
}

int calcNumCamera()
{
	int i, j, result = 0;
	for (i = 0; i < g; i++)
		if (!isVisited[i])		
			result += dfs(i);			
	for (i = 0; i < g; i++)
		if (!marked[i]) result++;
	return result;
}

int main(void)
{
    int i, j, result;
    scanf("%d", &c);

    for (i = 0; i < c; i++) {
		scanf("%d %d", &g, &h);
		memset(gallery, 0, MAX*MAX*sizeof(int));
		memset(isVisited, 0, MAX*sizeof(int));
		memset(marked, 0, MAX*sizeof(int));
		for (j = 0; j < h; j++) {
			scanf("%d %d", &tg1, &tg2);
			gallery[tg1][tg2] = 1;
			gallery[tg2][tg1] = 1;	
		}
		result = calcNumCamera();
		printf("%d\n", result);	
    }
}

