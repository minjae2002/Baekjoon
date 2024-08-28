#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long ll;

int parent[MAXN];
ll dist[MAXN];

int find(int x){
    if (parent[x] == x) return x;
    int root = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = root;
}

void unite(int x, int y, int w){
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY){
        dist[rootY] = dist[x] - dist[y] + w;
        parent[rootY] = rootX;
    }
}

int main(){
    while (true){
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < MAXN; i++) parent[i] = i;

        int N, M;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        
        while (M--){
            char what;
            scanf(" %c", &what);
            if (what == '!'){
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                unite(a, b, c);
            }
            else if (what == '?'){
                int a, b;
                scanf("%d %d", &a, &b);
                if (find(a) != find(b)) printf("UNKNOWN\n");
                else {
                    printf("%lld\n", dist[b] - dist[a]);
                }
            }
        }
    }
    return 0;
}