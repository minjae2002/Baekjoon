#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;                                        // 출발 노드, 도착 노드
#define INF 987654321

vector<int> dist;
vector<bool> visited;
vector<vector<edge>> Adjlist;
int N, M;

int Dijkstra(int start, int end){
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()){
        edge curNode = pq.top();
        pq.pop();
        int cur = curNode.second;

        if (!visited[cur]){
            visited[cur] = true;
            for (edge n : Adjlist[cur]){
                if (!visited[n.first] && dist[n.first] > dist[cur] + n.second){
                    dist[n.first] = dist[cur] + n.second;
                    pq.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }
    return dist[end];
}

int main(){
    scanf("%d", &N);
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), INF);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    Adjlist.resize(N + 1);

    scanf("%d", &M);
    
    for (int i = 0; i < M; i++){
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        Adjlist[start].push_back(make_pair(end, cost));
    }

    int startIdx, endIdx;
    scanf("%d %d", &startIdx, &endIdx);
    int result = Dijkstra(startIdx, endIdx);

    printf("%d", result);
    return 0;
}