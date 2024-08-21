#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define INF 1e9
typedef pair<int, int> edge;
typedef pair<int, pair<int, int>> point;

int N, weight = 0;
int planet[3][MAXN];
priority_queue<point, vector<point>, greater<>> pq;
int parent[MAXN];
int RANK[MAXN];

int find(int x){
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

int unite(int x, int y, int w){
    int rootX = find(x);
    int rootY = find(y);
    int distance = 0;
    if (rootX != rootY){
        if (RANK[x] >= RANK[y]){
            parent[rootY] = rootX;
            RANK[rootX] += RANK[rootY];
            RANK[rootY] = RANK[rootX];
        } else {
            parent[rootX] = rootY;
            RANK[rootY] += RANK[rootX];
            RANK[rootX] = RANK[rootY];
        }
        distance += w;
    }
    return distance;
}

void input(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d %d", &planet[0][i], &planet[1][i], &planet[2][i]);
        parent[i] = i;
        RANK[i] = 1;
    }
}

void add_edges() {
    for (int dim = 0; dim < 3; ++dim) {
        vector<pair<int, int>> points(N);
        for (int i = 0; i < N; ++i) {
            points[i] = make_pair(planet[dim][i], i);
        }
        sort(points.begin(), points.end());
        for (int i = 0; i < N - 1; ++i) {
            int cost = abs(points[i + 1].first - points[i].first);
            pq.push(make_pair(cost, make_pair(points[i].second, points[i + 1].second)));
        }
    }
}

int kruskal(){
    while(!pq.empty()){
        int d = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        weight += unite(a, b, d);
    }
    return weight;
}

int main(){
    input();
    add_edges();
    int ans = kruskal();
    printf("%d", ans);

    return 0;
}