#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF 1e18
typedef long long ll;
typedef pair<ll, ll> edge;

ll N, M;
vector<edge> V[MAXN];                       // (횡단보도가 켜지는 시점의 시간 mod M, 도착 지역)
vector<ll> reachtime;

void input(){
    scanf("%lld %lld", &N, &M);
    reachtime.resize(N + 1, INF);
    for (int i = 0; i < M; i++){
        ll a, b;
        scanf("%lld %lld", &a, &b); 
        V[a].push_back(make_pair(i, b));
        V[b].push_back(make_pair(i, a));
    }
}

void Dijkstra(){
    fill(reachtime.begin(), reachtime.end(), INF);
    reachtime[1] = 0;
    priority_queue<edge, vector<edge>, greater<>> pq;               // {reachtime[노드], 노드}
    pq.push(make_pair(0, 1));

    while (!pq.empty()){
        ll cur = pq.top().second;
        ll tmp = pq.top().first;
        pq.pop();
        if (tmp > reachtime[cur]) continue;

        for (auto& p : V[cur]){
            ll next = p.second;
            ll wtime = (p.first - (reachtime[cur] % M) + M) % M;
            ll ntime = reachtime[cur] + wtime + 1;
            
            if (reachtime[next] > ntime){
                reachtime[next] = ntime;
                pq.push(make_pair(reachtime[next], next));
            }
        }
    }
}

int main(){
    input();
    Dijkstra();
    printf("%lld", reachtime[N]);

    return 0;
}