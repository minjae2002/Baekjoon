#include <bits/stdc++.h>
using namespace std;
#define MAXN 102
#define INF 987654321

int n, m;
int cost[MAXN][MAXN];

void input(){
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c < cost[a][b]) cost[a][b] = c;
	}
}

void Solution(){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (cost[i][j] > cost[i][k] + cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (cost[i][j] == INF) printf("0 ");
			else printf("%d ", cost[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	input();
	Solution();
	
	return 0;
}