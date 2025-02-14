#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e4;

int N;
int arr[MAX + 1];
int dp[2][MAX/2 + 1];

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        if (arr[i] > min(i, (N - 1) - i)){
            printf("0\n");
            return 0;
        }
    }

    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 0; i < N; i++){
        int idx = i % 2;
        int pre = (idx + 1) % 2;
        for (int x = 0; x < MAX / 2; x++) dp[idx][x] = 0;

        if(arr[i] == -1){
            for (int x = 0; x < MAX / 2; ++x){
                if (x > min(i, (N - 1) - i)) break;
                for (int k = -1; k < 2; ++k){
                    int prex = x + k;
                    if (prex < 0) continue;

                    dp[idx][x] += dp[pre][prex];
                    dp[idx][x] %= MOD;
                }
            }
        }
        else {
            for (int k = -1; k < 2; ++k){
                int prex = arr[i] + k;
                if (prex < 0) continue;

                dp[idx][arr[i]] += dp[pre][prex];
                dp[idx][arr[i]] %= MOD;
            }
        }

        if (i == N - 1) printf("%d\n", dp[idx][0] % MOD);
    }

    return 0;
}