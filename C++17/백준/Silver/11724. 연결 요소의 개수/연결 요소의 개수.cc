#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Edge;
vector<bool> visited;

void DFS(int v){
    if (visited[v]) return;

    visited[v] = true;

    for (int i : Edge[v]){
        if (!visited[i]) DFS(i);
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    Edge.resize(N + 1);
    visited = vector<bool> (N + 1, false);

    for (int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++){
        if (!visited[i]){
            cnt++;
            DFS(i);
        }
    }

    printf("%d", cnt);

    return 0;
}