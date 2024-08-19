#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INF 1e9
typedef pair<int, int> edge;

int n, m, r;
int item[MAXN] = {0,};
int ans[MAXN] = {0,};
vector<edge> V[MAXN];
int dist[MAXN];

void input(){
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++){
        scanf("%d", &item[i]);
    }
    for (int i = 0; i < r; i++){
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        V[a].push_back(make_pair(l, b));
        V[b].push_back(make_pair(l, a));
    }
}

void Dijkstra(int start){
    fill(dist, dist + MAXN, INF);
    priority_queue<edge, vector<edge>, greater<>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()){
        int cur = pq.top().second;
        int cDist = pq.top().first;
        pq.pop();
        for (auto &p : V[cur]){
            int next = p.second;
            int nDist = cDist + p.first;
            if (dist[next] > nDist){
                dist[next] = nDist;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int countitem(int start){
    Dijkstra(start);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        if (dist[i] <= m){
            sum += item[i];
        }
    }
    return sum;
}

int main(){
    input();
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        cnt = max(cnt, countitem(i));
    }

    printf("%d", cnt);
    return 0;
}