#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
#define INF 1e9
typedef pair<int, int> edge;

int t, n, d, c;
int maxtime = 0, cnt = 0;
vector<edge> V[MAXN];                                       // V[a]에 (s, b) : a가 감염되면 s초 후 b도 감염
int lasttime[MAXN];                                             // 몇 초 뒤에 감염될지 저장

void Dijkstra(int s){
    fill(lasttime, lasttime + MAXN, INF);
    lasttime[s] = 0;
    priority_queue<edge, vector<edge>, greater<>> pq;       // (시간, 감염된 컴퓨터 번호)
    pq.push(make_pair(0, s));

    while (!pq.empty()){
        int cur = pq.top().second;
        int ctime = pq.top().first;
        pq.pop();

        for (auto &p : V[cur]){
            int next = p.second;
            int ntime = p.first + ctime;

            if (lasttime[next] > ntime){
                lasttime[next] = ntime;
                pq.push(make_pair(lasttime[next], next));
            }
        }
    }
}

void Solve(){
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d %d %d", &n, &d, &c);
        for (int j = 0; j < d; j++){
            int a, b, s;
            scanf("%d %d %d", &a, &b, &s);
            V[b].push_back(make_pair(s, a));
        }
        Dijkstra(c);
        for (int j = 1; j <= n; j++){
            if (lasttime[j] != INF){
                maxtime = max(maxtime, lasttime[j]);
                cnt++;
            }
        }
        printf("%d %d\n", cnt, maxtime);
        maxtime = 0;
        cnt = 0;
        for (int j = 0; j < MAXN; j++){
            V[j].clear();
        }
    }
}

int main(){
    Solve();
    return 0;
}