#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
typedef pair<int, int> edge;

int T, N, K, w;
int btime[MAXN] = {0,};
int indegree[MAXN] = {0,};
vector<edge> V[MAXN];                           // 간선의 가중치(이전 건물 건설 시간), 다음 건물
int reachtime[MAXN] = {0,};

int topology(int w){
    queue<int> q;
    for (int i = 1; i <= N; i++){
        if (indegree[i] == 0){
            q.push(i);
            reachtime[i] = btime[i];
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto& p : V[cur]){
            int next = p.second;
            int ntime = btime[next] + reachtime[cur];
            indegree[next]--;
            reachtime[next] = max(reachtime[next], ntime);
            if (indegree[next] == 0) q.push(next);
        }
    }
    return reachtime[w];
}

void Solve(){
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d", &N, &K);
        for (int j = 1; j <= N; j++){
            scanf("%d", &btime[j]);
            V[j].clear();
            indegree[j] = 0;
            reachtime[j] = 0;
        }
        for (int j = 0; j < K; j++){
            int x, y;
            scanf("%d %d", &x, &y);
            V[x].push_back(make_pair(btime[x], y));
            indegree[y]++;
        }
        scanf("%d", &w);
        int ans = topology(w);
        printf("%d\n", ans);
    }
}

int main(){
    Solve();
    return 0;
}