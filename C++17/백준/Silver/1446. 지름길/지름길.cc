#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 10001
typedef pair<int, int> edge;

int N, D;
vector<edge> V[MAX];
int dist[MAX];

void input(){
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c < b - a) V[a].push_back(make_pair(c, b));         // 지름길이 실제 거리보다 짧아야만 저장
    }
}

void Dijkstra(){
    fill(dist, dist + MAX, INF);  // 거리 정보 초기화
    dist[0] = 0;  // 시작점

    priority_queue<edge, vector<edge>, greater<>> pq;
    pq.push(make_pair(0, 0));  // (거리, 위치)

    while (!pq.empty()){
        int cur = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        // 현재 큐에 있는 정보가 dist에 저장된 정보보다 큰 경우 무시
        if (cCost > dist[cur]) continue;

        // 지름길 처리
        for (auto &p : V[cur]){
            int next = p.second;
            int nCost = cCost + p.first;
            if (dist[next] > nCost){
                dist[next] = nCost;
                pq.push(make_pair(nCost, next));
            }
        }

        // 다음 노드로 이동
        if (cur + 1 <= D && dist[cur + 1] > dist[cur] + 1){
            dist[cur + 1] = dist[cur] + 1;
            pq.push(make_pair(dist[cur + 1], cur + 1));
        }
    }
}

int main(){
    input();
    Dijkstra();
    printf("%d", dist[D]);
    return 0;
}