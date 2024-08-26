#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MOD 998244353
#define INF 1e18
typedef long long ll;
typedef pair<ll, ll> edge;

ll N, M;
ll dist[MAXN];
ll cntroute[MAXN];
vector<edge> V[MAXN];

void input(){
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < M; i++){
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        V[u].push_back(make_pair(w, v));
    }
}

void Dijkstra(){
    fill(dist, dist + N + 1, INF);
    fill(cntroute, cntroute + N + 1, 0);
    priority_queue<edge, vector<edge>, greater<>> pq;
    dist[1] = 0;
    cntroute[1] = 1;
    pq.push(make_pair(0, 1));

    while (!pq.empty()){
        ll cur = pq.top().second;
        ll ccost = pq.top().first;
        pq.pop();

        if (ccost > dist[cur]) continue;

        for (auto &p : V[cur]){
            ll next = p.second;
            ll ncost = p.first + ccost;

            if (dist[next] > ncost){
                dist[next] = ncost;
                cntroute[next] = cntroute[cur];
                pq.push(make_pair(dist[next], next));
            }
            else if (dist[next] == ncost){
                cntroute[next] += cntroute[cur];
                cntroute[next] %= MOD;
            }
        }
    }
}

int main(){
    input();
    Dijkstra();
    for (int i = 1; i <= N; i++){
        ll ans = cntroute[i];
        printf("%lld\n", ans);
    }

    return 0;
}