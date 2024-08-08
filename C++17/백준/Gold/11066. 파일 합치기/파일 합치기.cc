#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int T, K;
int DP[MAX][MAX];
int matrix[MAX];
int sum[MAX] = {0,};

int dfs(int l, int r){
	if (l == r) return DP[l][r] = 0;
	if (DP[l][r] != -1) return DP[l][r];
	
	int minv = 987654321;
	for (int k = l; k < r; k++){
		int L = dfs(l, k);
		int R = dfs(k + 1, r);
		int leftsum = sum[k] - sum[l - 1];
		int rightsum = sum[r] - sum[k];
		int res = leftsum + rightsum;
		int total = L + R + res;
		minv = min(minv, total);
	}
	return DP[l][r] = minv;
}

void Solution(){
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d", &K);
        for (int j = 1; j <= K; j++){
            int n;
            scanf("%d", &n);
            matrix[j] = n;
            sum[j] = sum[j - 1] + n;
        }
        memset(DP, -1, sizeof(DP)); // DP 테이블 초기화
        int ret = dfs(1, K);
        printf("%d\n", ret);
    }
} 

int main(void){
	memset(&DP, -1, sizeof(DP));
	Solution();
	return 0;
}