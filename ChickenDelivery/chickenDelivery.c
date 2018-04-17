#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 51
#define M_MAX 13

int N, M;
int chick_idx = 0;
int house_idx = 0;

int house_x[N_MAX*N_MAX];
int house_y[N_MAX*N_MAX];

int chick_x[N_MAX*N_MAX];
int chick_y[N_MAX*N_MAX];


int min_dist = 99999999;

int abs(int a)
{
	return a > 0? a: -a;
}

void add_house(int x, int y)
{
	house_x[house_idx] = x;
	house_y[house_idx++] = y;
}

void add_chicken(int x, int y)
{
	chick_x[chick_idx] = x;
	chick_y[chick_idx++] = y;
}

int calc_dist(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2)+abs(y1-y2);	
}

void combination(int *arr, int n, int r, int idx, int assign) {
	int i, j, dist, chick_dist;
	int sum_dist = 0;
	if (r == 0) {
		for (i = 0; i < house_idx; i++) {
			chick_dist = 99999;	
			for (j = 0; j < idx; j++) {
				dist = calc_dist(house_x[i], house_y[i],
				chick_x[arr[j]], chick_y[arr[j]]);
				if (dist < chick_dist) chick_dist = dist;
			}
			sum_dist += chick_dist; 
		}
			
		if (min_dist > sum_dist) { 
				min_dist = sum_dist;
		}
		return ;
	}
	if (assign == n)	return ;
	
	arr[idx] = assign; 
	combination(arr, n, r-1, idx+1, assign+1);
	combination(arr, n, r, idx,  assign+1);
}

int main(void)
{
	int i, j, ij, result = 0;
	int *arr;

	scanf("%d %d", &N, &M);
	arr = (int *) malloc (sizeof(int)*M);
	memset(arr, 0, sizeof(int)*M);
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) {
			scanf("%d", &ij);
			if (ij == 1) add_house(i+1, j+1);
			else if (ij == 2) add_chicken(i+1, j+1);
		}
	
	combination(arr, chick_idx, M, 0, 0); 
	if (M == 0)	printf("0\n");
	else printf("%d\n", min_dist);
	free(arr);
}
