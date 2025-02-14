#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans, sum;
int bite[101], cost[101];
int dp[101][10001];

int main(){
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) scanf("%d", &bite[i]);
    for (int i = 1; i <= N; i++){
        scanf("%d", &cost[i]);
        sum += cost[i];
    }

    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= sum; j++){
            if (j - cost[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++){
        if (dp[N][i] >= M){
            printf("%d", i);
            break;
        }
    }

    return 0;
}