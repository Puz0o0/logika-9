#define _CTR_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int dist[5]={-1};

int **createG(int size){
	int **G = NULL;
	G = (int**)malloc(size*sizeof(int*));

	for (int i = 0; i < size; i++){
		G[i] = (int *)malloc(size*sizeof(int));
	}
	for(int i = 0; i < size; i++){
		for (int j = i; j < size; j++){
			G[i][j] = rand()%2;
			if(i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void printG(int **G, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%d", G[i][j]);
		}
		printf("\n");
	}
}

void DFS (int **G, int size, int *vis, int s){
	queue <int> q;

	q.push(s);

	dist[s]=0;

	while(!q.empty()){
		s = q.front();

		q.pop();

		for(int i = 0; i < size; i++){
			if (G[i][s]=1 && dist[i]==-1){

			q.push(i);

			dist[i] = dist[s] + 1;
			}
		} 

	}
}
int main () {
	int **G=NULL;
	int *vis=NULL;
	int size=5;
	int s=1;

	printf("Vvedite kill-vo vershin: ");
	scanf_s("%d", &size);

	G=createG(size);
	printG(G, size);
	printf("Vvedite nachalnuyu vershinu: ");

	vis = (int*)malloc(size*sizeof(int));
	for (int i = 0; i < size; i++)
	{vis[i] =0;}

	scanf_s("%d", &s);
	printf("Obhod grafa: \n");
	DFS( G, size, vis, s);

	printf("Oblast' rasstoyaniy: \n");

	for(int i = 0; i < size; i++){
		dist[i] = -1;
		}

	DFS(G, size, vis, s);

	for(int i = 0; i < size; i++){
		printf("Rastoyanie do %d vershini: %d\n", i, dist[i]);
		}
		scanf_s("%d", &s);
	return 0;

}
