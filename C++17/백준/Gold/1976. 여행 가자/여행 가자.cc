#include <bits/stdc++.h>
using namespace std;
#define MAXN 201
#define MAXM 1001

vector<int> parent;

int find(int a){
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if (a != b){
        parent[b] = a;
    }
}

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int city[MAXN][MAXN];
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            scanf("%d", &city[i][j]);
        }
    }

    int route[MAXM];
    for (int i = 1; i <= M; i++){
        scanf("%d", &route[i]);
    }

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (city[i][j] == 1){
                Union(i, j);
            }
        }
    }

    int idx = find(route[1]);
    bool connect = true;

    for (int i = 2; i <= M; i++){
        if (idx != find(route[i])){
            printf("NO");
            connect = false;
            break;
        }
    }

    if (connect) printf("YES");

    return 0;
}