#include <bits/stdc++.h>
using namespace std;
#define MAXN 802
#define INF 987654321
typedef pair<int, int> edge;
typedef long long ll;

int N, E, u, v;
ll ans;
vector<edge> V[MAXN];
int dist[MAXN];

void input(){
    scanf("%d %d", &N, &E);
    for (int i = 0; i < E; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back(make_pair(c, b));                        // V : (비용(거리), 연결된 노드)
        V[b].push_back(make_pair(c, a));
    }
}

void Dijkstra(int S){
    priority_queue<edge, vector<edge>, greater<>> pq;           // S부터 '얼마'의 비용으로 '어디'를 갈 수 있나?
    fill(dist, dist + N + 1, INF);
    dist[S] = 0;
    pq.push(make_pair(0, S));

    while (!pq.empty()){
        int cur = pq.top().second;
        int cdist = pq.top().first;
        pq.pop();

        for (int i = 0; i < V[cur].size(); i++){
            int next = V[cur][i].second;
            int ndist = V[cur][i].first;

            if (dist[next] > cdist + ndist){
                dist[next] = cdist + ndist;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

void Solve(){
    scanf("%d %d", &u, &v);
    Dijkstra(1);
    ll dist1u = dist[u];
    ll dist1v = dist[v];

    Dijkstra(N);
    ll distNu = dist[u];
    ll distNv = dist[v];

    Dijkstra(u);
    ll distuv = dist[v];

    ll route1 = dist1u + distuv + distNv;
    ll route2 = dist1v + distuv + distNu;

    ans = min(route1, route2);

    if (ans >= INF || dist1u == INF || dist1v == INF || distNu == INF || distNv == INF || distuv == INF) {
        ans = -1;
    }
}

int main(){
    input();
    Solve();
    printf("%lld", ans);
    return 0;
}