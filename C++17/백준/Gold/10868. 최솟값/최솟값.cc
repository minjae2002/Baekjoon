#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF 1e9

int B = 1;
vector<int> tree;

void init(){
    for (int i = B - 1; i > 0; i--){
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
}

int findmin(int a, int b){
    int s = B + a - 1;
    int e = B + b - 1;
    int tmp1 = INF, tmp2 = INF;

    while (s <= e){
        if (s % 2 == 1){
            tmp1 = min(tmp1, tree[s]);
            s++;
        }
        if (e % 2 == 0){
            tmp2 = min(tmp2, tree[e]);
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return min(tmp1, tmp2);
}

void Solve(){
    int N, M;
    scanf("%d %d", &N, &M);
    while (B < N) B *= 2;

    tree.resize(2 * B, INF);

    for (int i = 0; i < N; i++){
        scanf("%d", &tree[B + i]);
    }
    init();

    for (int j = 0; j < M; j++){
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = findmin(a, b);
        printf("%d\n", ans);
    }
}

int main(){
    Solve();
    return 0;
}