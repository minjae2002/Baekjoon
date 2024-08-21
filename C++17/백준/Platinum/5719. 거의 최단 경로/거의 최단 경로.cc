#include <iostream>
#include <vector>
#include <queue>
#include <utility>  // pair를 사용하기 위해 필요
#include <algorithm> // fill 함수 사용을 위해 필요
#define MAXN 501
#define INF 1e9
using namespace std;
typedef pair<int, int> edge;

int N, M, S, D, U, V, P;
vector<edge> graph[2][MAXN];
int dist[2][MAXN];                                          // 0행은 정방향 그래프로 S에서 다익스트라, 1행은 역방향 그래프로 D에서 다익스트라
int almost[MAXN];

void Dijkstra(int s, int k){                                // k가 0이면 정방향 다익스트라, k가 1이면 역방향 다익스트라
    for (int i = 0; i < MAXN; i++){
        dist[k][i] = INF;
    }

    dist[k][s] = 0;
    priority_queue<edge, vector<edge>, greater<>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()){
        int cur = pq.top().second;
        int ctime = pq.top().first;
        pq.pop();

        for (auto &p : graph[k][cur]){
            int next = p.second;
            int ntime = ctime + p.first;
            if (dist[k][next] > ntime){
                dist[k][next] = ntime;
                pq.push(make_pair(dist[k][next], next));
            }
        }
    }
}

void almostDijkstra(int s){
    fill(almost, almost + MAXN, INF);
    priority_queue<edge, vector<edge>, greater<>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()){
        int cur = pq.top().second;
        int ctime = pq.top().first;
        pq.pop();

        for (auto &p : graph[0][cur]){
            int next = p.second;
            int ntime = ctime + p.first;

            if (dist[0][cur] + p.first + dist[1][next] == dist[0][D]) continue;

            if (almost[next] > ntime){
                almost[next] = ntime;
                pq.push(make_pair(almost[next], next));
            }
        }
    }
}

void Solve(){
    Dijkstra(S, 0);
    Dijkstra(D, 1);
    almostDijkstra(S);
}

int main(){
    while (true){
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        scanf("%d %d", &S, &D);

        for (int i = 0; i < N; i++) {
            graph[0][i].clear();
            graph[1][i].clear();
        }

        for (int i = 0; i < M; i++){
            scanf("%d %d %d", &U, &V, &P);
            graph[0][U].push_back(make_pair(P, V));
            graph[1][V].push_back(make_pair(P, U));
        }
        Solve();
        if (almost[D] == INF) printf("-1\n");
        else printf("%d\n", almost[D]);

    }
    
    return 0;
}