#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAXN 1001
typedef pair<int, int> edge;                                    // 시간, 노드

int N, M, X;
vector<edge> graph[2][MAXN];
vector<int> dist[2];
int resdist[MAXN];

void input(){
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < M; i++){
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        graph[0][u].push_back(make_pair(t, v));                 // 정방향 그래프 (나로부터 다른 정점들까지의 최단 거리)
        graph[1][v].push_back(make_pair(t, u));                 // 역방향 그래프 (다른 정점들로부터 나까지의 최단 거리)
    }
    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);
}

void dijkstra(int k){
    dist[k][X] = 0;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push(make_pair(0, X));
    
    while (!pq.empty()){
        int min_cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (min_cost > dist[k][now]) continue;
        for (int i = 0; i < graph[k][now].size(); i++){
            int next = graph[k][now][i].second;
            int next_cost = min_cost + graph[k][now][i].first;

            if (next_cost < dist[k][next]){
                dist[k][next] = next_cost;
                pq.push(make_pair(next_cost, next));
            }
        }
    }
}

int main(void){
    input();
    dijkstra(1);
    dijkstra(0);
    int res = 0;
    for (int i = 1; i <= N; i++){
        res = max(res, dist[0][i] + dist[1][i]);
    }

    printf("%d", res);
    return 0;
}