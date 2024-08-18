#include <bits/stdc++.h>
using namespace std;
#define MAXN 300001
#define INF 1e9

vector<int> G[MAXN];
int dist[MAXN];

int N, M, K, X;
int a, b;

void input(){
    scanf("%d %d %d %d", &N, &M, &K, &X);
    for (int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }
}

void bfs(int S){
    queue<int> q;
    fill(dist, dist + MAXN, INF);
    q.push(S);
    dist[S] = 0;

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < G[cur].size(); i++){
            int next = G[cur][i];
            if (dist[next] > dist[cur] + 1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

void Solve(){
    bfs(X);
    bool found = false;
    for (int i = 1; i <= N; i++){
        if (dist[i] == K){
            found = true;
            printf("%d\n", i);
        }
    }
    
    if (!found) printf("-1\n");
}

int main(){
    input();
    Solve();

    return 0;
}