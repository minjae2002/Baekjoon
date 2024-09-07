#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n;
int V[MAXN][3];                     // i (MAXN)번째 집을 어떤 색(R, G, B)으로 칠했을 때의 비용 저장

int main(){
    scanf("%d", &n);
    V[0][0] = 0;
    V[1][0] = 0;
    V[2][0] = 0;
    for (int i = 1; i <= n; i++){
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        V[i][0] = min(V[i - 1][1], V[i - 1][2]) + r;
        V[i][1] = min(V[i - 1][0], V[i - 1][2]) + g;
        V[i][2] = min(V[i - 1][0], V[i - 1][1]) + b;
    }

    int ans = min(V[n][0], min(V[n][1], V[n][2]));
    printf("%d", ans);

    return 0;
}