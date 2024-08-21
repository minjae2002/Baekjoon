#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> edge;
#define MAXV 10001
#define MAXE 100001

int V, E;
priority_queue<edge, vector<edge>, greater<>> pq;
int parent[MAXV];
int Rank[MAXV];
ll totalweight = 0;

void input(){
    scanf("%d %d", &V, &E);
    while (E--){
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        pq.push(make_pair(c, make_pair(a, b)));
    }
}

void initialize(){
    for (int i = 1; i <= V; i++){
        parent[i] = i;
        Rank[i] = 1;
    }
}

int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

ll unionV(int x, int y, ll w){
    int rootX = find(x);
    int rootY = find(y);
    ll weight = 0;
    if (rootX != rootY){
        if (Rank[x] >= Rank[y]){
            parent[rootX] = rootY;
            Rank[rootY] += Rank[rootX];
            Rank[rootX] = Rank[rootY];
        } else {
            parent[rootY] = rootX;
            Rank[rootX] += Rank[rootY];
            Rank[rootY] = Rank[rootX];
        }
        weight = w;
    }
    return weight;
}

ll kruskal(){
    ll weight = 0;
    while (!pq.empty()){
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        ll w = pq.top().first;
        pq.pop();

        totalweight += unionV(a, b, w);
    }
    return totalweight;
}

int main(){
    input();
    initialize();
    ll ans = kruskal();

    printf("%lld", ans);
    return 0;
}