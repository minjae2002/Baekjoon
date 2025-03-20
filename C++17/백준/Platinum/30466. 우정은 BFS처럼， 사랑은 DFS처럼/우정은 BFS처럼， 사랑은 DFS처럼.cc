#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;

void input(){
    scanf("%d", &N);
}

ll Solve(int N){
    int m = N / 2;
    ll ans = (ll)(m - 1) * (N * 2 - m * 2 - 2);

    return ans;
}

void printEdge(int N){
    int m = N / 2;

    for (int i = 1; i <= m; i++){
        printf("%d %d\n", i, i + 1);
    }
    for (int i = m + 2; i <= N; i++){
        printf("%d %d\n", 1, i);
    }
}

int main(){
    input();
    ll max = Solve(N);
    printf("%lld\n", max);
    printEdge(N);

    return 0;
}