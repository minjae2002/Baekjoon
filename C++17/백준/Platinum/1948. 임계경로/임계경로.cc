#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
#define MAXN 10001

int n, m, s, e;
int reachtime[MAXN] = {0,};
int indegree[MAXN] = {0,};
vector<edge> V[MAXN];                           // 도착 시간, 다음 노드
vector<edge> inv[MAXN];

void input(){
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back(make_pair(c, b));
        inv[b].push_back(make_pair(c, a));
        indegree[b]++;
    }
    scanf("%d %d", &s, &e);
}

void timeupdate(int s){
    fill(reachtime, reachtime + MAXN, 0);
    queue<edge> q;
    q.push(make_pair(0, s));

    while(!q.empty()){
        int cur = q.front().second;
        int ctime = q.front().first;
        q.pop();

        for (auto& p: V[cur]){
            int next = p.second;
            int ntime = p.first + ctime;
            reachtime[next] = max(reachtime[next], ntime);
            indegree[next]--;
            if (indegree[next] == 0) q.push(make_pair(reachtime[next], next));
        }
    }
}

int bfs(int s){
    int cnt = 0;
    vector<bool> visited(MAXN, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto& p: inv[cur]){
            if (reachtime[cur] == reachtime[p.second] + p.first){
                cnt++;
                if (!visited[p.second]){
                    visited[p.second] = true;
                    q.push(p.second);
                }
            } 
        }
    }
    return cnt;
}

void Solve(){
    timeupdate(s);
    printf("%d\n", reachtime[e]);
    int count = bfs(e);
    printf("%d\n", count);
}

int main(){
    input();
    Solve();

    return 0;
}