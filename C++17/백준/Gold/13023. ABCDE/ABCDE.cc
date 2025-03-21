#include <bits/stdc++.h>
using namespace std;

int N, M;
bool arrive = false;
vector<vector<int>> F;
vector<bool> visited;

void input(){
    scanf("%d %d", &N, &M);
    F.resize(N);
    visited = vector<bool> (N, false);

    for (int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        F[a].push_back(b);
        F[b].push_back(a);
    }
}

void DFS(int now, int depth){
    if (depth == 5 || arrive){
        arrive = true;
        return;
    }
    visited[now] = true;

    for (auto &i : F[now]){
        if (!visited[i]) DFS(i, depth + 1);
    }

    visited[now] = false;
}

void Solve(){
    for (int i = 0; i < N; i++){
        DFS(i, 1);
        if (arrive) break;
    }
    if (arrive) printf("1");
    else printf("0");
}

int main(){
    input();
    Solve();

    return 0;
}