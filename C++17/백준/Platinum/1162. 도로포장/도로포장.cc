#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
#define INF 1e18
typedef long long ll;
typedef pair<ll, int> edge;                                     // 거리, 정점
typedef pair<ll, pair<int, int>> state;                         // 거리, (정점, 포장 횟수)

int N, M, K;
ll ans = INF;
vector<edge> V[MAXN];
ll dist[MAXN][21];

void input(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++){
        int a, b;
        ll t;
        scanf("%d %d %lld", &a, &b, &t);
        V[a].push_back({t, b});
        V[b].push_back({t, a});
    }
}

void Dijkstra(int s){
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= K; j++){
            dist[i][j] = INF;
        }
    }

    priority_queue<state, vector<state>, greater<>> pq;
    pq.push(make_pair(0, make_pair(s, 0)));
    dist[s][0] = 0;

    while (!pq.empty()){
        int cur = pq.top().second.first;
        int cnt = pq.top().second.second;
        ll val = pq.top().first;
        pq.pop();

        if (dist[cur][cnt] < val) continue;

        for (auto &p : V[cur]){
            int next = p.second;
            ll new_val = val + p.first;

            if (dist[next][cnt] > new_val){
                dist[next][cnt] = new_val;
                pq.push(make_pair(new_val, make_pair(next, cnt)));
            }

            // 포장을 한 경우
            if (cnt < K && dist[next][cnt + 1] > val) {
                dist[next][cnt + 1] = val;
                pq.push(make_pair(val, make_pair(next, cnt + 1)));
            }
        }
    }
}

int main(){
    input();
    Dijkstra(1);
    for (int i = 0; i <= K; i++){
        ans = min(ans, dist[N][i]);
    }
    printf("%lld", ans);

    return 0;
}
