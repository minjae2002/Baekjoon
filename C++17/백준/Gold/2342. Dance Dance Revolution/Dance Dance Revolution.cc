#include <cstdio>
#include <algorithm>
#define MAX 100001
#define INF 987654321
using namespace std;

int dp[5][5][MAX];

// 두 발이 cur에서 next로 이동할 때 드는 힘을 반환하는 함수
int getCost(int cur, int next){
    if(cur == 0) return 2;            // 중앙(0)에서 다른 지점으로: 2
    if(cur == next) return 1;         // 같은 지점을 다시 누를 때: 1
    // 반대편: 1과 3, 2와 4
    if((cur == 1 && next == 3) || (cur == 3 && next == 1) ||
       (cur == 2 && next == 4) || (cur == 4 && next == 2))
        return 4;
    return 3;                       // 그 외 (인접한 지점): 3
}

int main(){
    // dp 배열을 INF로 초기화
    for (int s = 0; s < MAX; s++){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                dp[i][j][s] = INF;
            }
        }
    }
    dp[0][0][0] = 0;  // 시작 상태: 두 발 모두 중앙(0)

    int n, idx = 0;
    while(true){
        scanf("%d", &n);
        if(n == 0) break;  // 0은 입력 종료

        // 현재 단계 idx에서 가능한 모든 상태에 대해 전이
        for (int left = 0; left < 5; left++){
            for (int right = 0; right < 5; right++){
                if(dp[left][right][idx] == INF) continue;

                // 만약 이미 한 발이 n에 있다면, 그 발로만 누를 수 있음 (비용 1)
                if(left == n || right == n){
                    dp[left][right][idx+1] = 
                        std::min(dp[left][right][idx+1], dp[left][right][idx] + 1);
                } else {
                    // 두 발 모두 n이 아니라면, 각 발을 움직이는 전이를 고려
                    // 단, 이동 후 두 발이 같은 위치가 되어서는 안 됨.
                    // 왼쪽 발을 n으로 이동 (단, 오른쪽 발과 겹치지 않아야 함)
                    if(n != right)
                        dp[n][right][idx+1] = 
                            std::min(dp[n][right][idx+1], dp[left][right][idx] + getCost(left, n));
                    // 오른쪽 발을 n으로 이동 (단, 왼쪽 발과 겹치지 않아야 함)
                    if(n != left)
                        dp[left][n][idx+1] = 
                            std::min(dp[left][n][idx+1], dp[left][right][idx] + getCost(right, n));
                }
            }
        }
        idx++;
    }
    
    int ans = INF;
    // 마지막 단계(idx)에서 가능한 모든 상태 중 최소 비용을 찾음
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            ans = std::min(ans, dp[i][j][idx]);
        }
    }
    printf("%d", ans);
    return 0;
}
