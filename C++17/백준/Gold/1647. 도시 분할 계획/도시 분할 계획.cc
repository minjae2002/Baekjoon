#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
#define MAXN 100001

int N, M;
int weight = 0;
int tmp;
int parent[MAXN];
int RANK[MAXN];
priority_queue<edge, vector<edge>, greater<>> pq;

void input(){
    scanf("%d %d", &N, &M);
    while (M--){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        pq.push(make_pair(C, make_pair(A, B)));
    }
}

void init(){
    for (int i = 1; i <= N; i++){
        parent[i] = i;
        RANK[i] = 1;
    }
}

int find(int x){
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void unionV(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY){
        if (RANK[x] >= RANK[y]){
            parent[rootX] = rootY;
            RANK[rootY] += RANK[rootX];
            RANK[rootX] = RANK[rootY];
        } else {
            parent[rootY] = rootX;
            RANK[rootX] += RANK[rootY];
            RANK[rootY] = RANK[rootX];
        }
    }
}

int main(){
    input();
    init();
    while (!pq.empty()){
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();

        if (find(a) != find(b)){
            unionV(a, b);
            weight += w;
            tmp = w;
        }
    }
    int ans = weight - tmp;
    printf("%d\n", ans);

    return 0;
}