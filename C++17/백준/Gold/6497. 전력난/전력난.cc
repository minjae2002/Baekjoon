#include <bits/stdc++.h>
using namespace std;
#define MAX 200001
typedef long long ll;
typedef pair<int, int> edge;
typedef pair<ll, edge> cedge;

int m, n;
ll tot = 0;
ll weight = 0;
int parent[MAX] = {0,};
int RANK[MAX];
priority_queue<cedge, vector<cedge>, greater<>> pq;

int find(int a){
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void unite(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB){
        if (RANK[a] >= RANK[b]){
            parent[rootB] = rootA;
            RANK[a] += RANK[b];
            RANK[b] = RANK[a];
        } else {
            parent[rootA] = rootB;
            RANK[b] += RANK[a];
            RANK[a] = RANK[b];
        }
    }
}

ll kruskal(){
    while (!pq.empty()){
        ll d = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if (find(a) != find(b)){
            unite(a, b);
            weight += d;
        }
    }
    return weight;
}

int main(){
    while(true){
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        tot = 0;
        weight = 0;

        for (int i = 0; i < m; i++){
            parent[i] = i;
            RANK[i] = 1;
        }

        for (int i = 0 ; i < n; i++){
            int x, y;
            ll z;
            scanf("%d %d %lld", &x, &y, &z);
            pq.push(make_pair(z, make_pair(x, y)));
            tot += z;
        }
        ll mst = kruskal();
        ll ans = tot - mst;
        printf("%lld\n", ans);

        while (!pq.empty()) pq.pop();
    }
    return 0;
}