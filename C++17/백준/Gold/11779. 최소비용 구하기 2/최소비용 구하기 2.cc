#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define INF 1e9
typedef pair<int, int> edge;

int n, m, S, E;
vector<edge> busmap[MAXN];                              // 출발 도시와 도착 도시, 버스 비용 저장
int cost[MAXN];                                         // 각 도시까지 가는 최소 비용들
int pre[MAXN];                                          // (최소 비용 기준) 어디서 나한테 왔는지 저장
vector<int> route;

void input(){                                           // 버스 정보들 입력 받아 저장
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b, c;                                    // 출발 도시, 도착 도시, 버스 비용.
        scanf("%d %d %d", &a, &b, &c);
        busmap[a].push_back(make_pair(c, b));           // (비용, 도착 도시)
    }
    scanf("%d %d", &S, &E);
}

void Dijkstra(int start){
    fill(cost, cost + MAXN, INF);
    priority_queue<edge, vector<edge>, greater<>> pq;   // (비용, 도착 도시)
    cost[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()){
        int cur = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        if (cCost > cost[cur]) continue;

        for (int i = 0; i < busmap[cur].size(); i++){
            int next = busmap[cur][i].second;
            int nCost = busmap[cur][i].first;

            if (cost[next] > cCost + nCost){
                cost[next] = cCost + nCost;
                pre[next] = cur;
                pq.push(make_pair(cost[next], next));
            }
        }
    }
}

void Solve(int s, int e){
    int cur = e;
    route.push_back(cur);
    while (cur != s){
        int prev = pre[cur];
        route.push_back(prev);
        cur = prev;
    }
}


int main(){
    input();
    Dijkstra(S);
    Solve(S, E);
    printf("%d\n", cost[E]);
    printf("%d\n", route.size());
    for (int i = route.size() - 1; i >= 0; i--){
        printf("%d ", route[i]);
    }

    return 0;
}