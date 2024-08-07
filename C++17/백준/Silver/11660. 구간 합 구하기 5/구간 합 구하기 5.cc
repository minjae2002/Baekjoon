#include <bits/stdc++.h>
using namespace std;

#define MAXN 1025
int chart[MAXN][MAXN];
int DP[MAXN][MAXN] = {0,}; 
int N, M;

void input(){
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &chart[i][j]);
		}
	}
}

void update(int n){
	int score = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + chart[i][j];
		}
	}
}

int main(){
	input();
	update(N);
	int a, b, c, d;
	for (int i = 1; i <= M; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int ans = DP[c][d] - DP[a - 1][d] - DP[c][b - 1] + DP[a - 1][b - 1];
		printf("%d\n", ans);
	}
	
	return 0;	
}