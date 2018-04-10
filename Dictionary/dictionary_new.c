#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define ARR_SIZE 26
#define ROOT_IDX 26

char word[1000][ARR_SIZE];
int graph[ARR_SIZE][ARR_SIZE];
int seen[ARR_SIZE];
int ordered[ARR_SIZE];
int C;
int N;
int glb_idx;
int is_cycle;

int minSize(char *a, char *b) {
	int sizeA = strlen(a);
	int sizeB = strlen(b);
	return sizeA >= sizeB? sizeB : sizeA;
}

void makeGraph() {
	int i, j, size;
	for (i = 1; i < N; i++) {
		size = minSize(word[i-1], word[i]);
	//	printf("size: %d\n", size);
		for (j = 0; j < size; j++) {
			if (word[i-1][j] != word[i][j]) {
	//			printf("Graph error?\n");
	//			printf("Graph error?: %c %c\n", word[i-1][j], word[i][j]);
				graph[word[i-1][j]-'a'][word[i][j]-'a'] = 1;
				if (graph[word[i][j]-'a'][word[i-1][j]-'a'] == 1) {
					is_cycle = 1;
				}
				break;	
			}
		}	
	}
}

void dfs(int here) {
	int i, j;
	if (seen[here])	return ;

	seen[here] = 1;
	for (i = 0; i < ARR_SIZE; i++)
		if (graph[here][i]==1) {
			 dfs(i);
		}
		 
	ordered[glb_idx++] = here;
}

void makeOrder() {
	int i, j;
	for (i = 0; i < ARR_SIZE; i++) {
		//for (j = 0; j < ARR_SIZE; j++) {
			//if (graph[i][j] == 1) {
				dfs(i);		
			//	break;
			//}
		//}
	}
}

void printResult() {
	int i, j, not_ordered;
		
	for (i = 0; i < ARR_SIZE; i++)
		for (j=i+1; j < ARR_SIZE; j++)
			if (graph[ordered[i]][ordered[j]]) {
				printf("INVALID HYPOTHESIS\n");
				return ;
			} 

	for (i = glb_idx-1; i >= 0; i--)
		printf("%c", ordered[i]+'a');
/*
	for (i = 0; i < ARR_SIZE; i++) {
		not_ordered = 0;
		for (j = 0; j < glb_idx; j++) {
			if (i == ordered[j]) {
				not_ordered = 1;
				break;
			}
		}
		if (not_ordered == 0)
			printf("%c", i+'a');
	}
*/
	printf("\n");
}

int main(void)
{
    int i, j, k; 
    scanf("%d", &C);
	for (i = 0; i < C; i++) {
		glb_idx = 0;
		is_cycle = 0;
		scanf("%d", &N);
		for (j = 0; j < 1000; j++)
			for (k = 0; k < ARR_SIZE; k++)
				word[j][k]=0;
		for (j = 0; j <ARR_SIZE; j++) {
			for (k = 0; k < ARR_SIZE; k++) {
				graph[j][k] = 0;
			}
			seen[j] = 0;
			ordered[j] = 0;	
		}
		for (j = 0; j < N; j++) {
				scanf("%s", word[j]);	
//				printf("OK\n");
		}
//		printf("OK INPUT FINISH\n");

		makeGraph();
//		printf("OK GRAPH FINISH\n");
		if (is_cycle == 0) {
			makeOrder();
//			printf("OK ORDER FINISH\n");
			printResult();
//			printf("OK PRINT FINISH\n");
		} else {
			printf("INVALID HYPOTHESIS\n");
		}
		/*
		for (j = 0; j < ARR_SIZE; j++)
			for (k = 0; k < ARR_SIZE; k++)
				printf("[%c][%c]:  %d", j+'a', k+'a', graph[j][k]);
			printf("\n");
		*/
	}	
}
