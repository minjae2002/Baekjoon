#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int N;
int DP[MAX][MAX];
int matrix[MAX][2];

int dfs(int l, int r){
	if (l == r) return DP[l][r] = 0;
	if (DP[l][r] != -1) return DP[l][r];
	
	int minv = 987654321;
	for (int k = l; k < r; k++){
		int L = dfs(l, k);
		int R = dfs(k + 1, r);
		int res = matrix[l][0] * matrix[k][1] * matrix[r][1];
		int total = L + R + res;
		minv = min(minv, total);
	}
	return DP[l][r] = minv;
}

void Solution(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d %d", &matrix[i][0], &matrix[i][1]);
	}
	int ret = dfs(1, N);
	printf("%d\n", ret);
} 

int main(void){
	memset(&DP, -1, sizeof(DP));
	Solution();
	return 0;
}