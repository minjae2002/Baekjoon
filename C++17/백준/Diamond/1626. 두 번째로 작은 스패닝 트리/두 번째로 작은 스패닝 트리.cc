#include <bits/stdc++.h>
#define MAX 50001
#define DMAX 16
#define INF INT_MAX
using namespace std;

typedef pair<int, int> pii;

int V, E;
struct Edge{
    int A, B, W;
    bool Used = false;
    Edge():Edge(0,0,0){}
    Edge(int a1, int b1, int w1): A(a1), B(b1), W(w1){}
};

vector<Edge> Vec;
bool cmp(const Edge &E1, const Edge &E2){
    return E1.W < E2.W;
}

int R[MAX + 1];
int Find(int x){
    if (R[x] == 0) return x;
    return R[x] = Find(R[x]);
}
void Union(int x, int y){
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    R[yRoot] = xRoot;
}

vector<pii> adj[MAX + 1];
int Depth[MAX + 1];
int parent[MAX + 1][DMAX + 1];
pii Biggest[MAX + 1][DMAX + 1];

void MakeDepth(int curr){
    for (auto child: adj[curr]){
        if (Depth[child.first] != 0) continue;
        Depth[child.first] = Depth[curr] + 1;
        parent[child.first][0] = curr;
        Biggest[child.first][0] = pii(child.second, -1);
        MakeDepth(child.first);
    }
}

int HowAboutThis(Edge EE){
    int x = EE.A;
    int y = EE.B;
    int w = EE.W;

    int ret = -1;
    if (Depth[x] < Depth[y]) swap(x, y);
    int diff = Depth[x] - Depth[y];
    int cnt = 0;
    while(diff){
        if (diff % 2 == 1){
            if (Biggest[x][cnt].first != w){
                ret = max(ret, Biggest[x][cnt].first);
            }
            else if (Biggest[x][cnt].second != -1){
                ret = max(ret, Biggest[x][cnt].second);
            }
            x = parent[x][cnt];
        }
        diff /= 2;
        cnt++;
    }

    if (x != y){
        for (int i = DMAX; i >= 0; i--){
            if (parent[x][i] != parent[y][i]){
                if (Biggest[x][i].first != w) ret = max(ret, Biggest[x][i].first);
                else if (Biggest[x][i].second != -1) ret = max(ret, Biggest[x][i].second);
                if (Biggest[y][i].first != w) ret = max(ret, Biggest[y][i].first);
                else if (Biggest[y][i].second != -1) ret = max(ret, Biggest[y][i].second);

                x = parent[x][i];
                y = parent[y][i];
            }
        }
        if (Biggest[x][0].first != w) ret = max(ret, Biggest[x][0].first);
        else if (Biggest[x][0].second != -1) ret = max(ret, Biggest[x][0].second);
        if (Biggest[y][0].first != w) ret = max(ret, Biggest[y][0].first);
        else if (Biggest[y][0].second != -1) ret = max(ret, Biggest[y][0].second);

        x = parent[x][0];
    }
    return ret;
}

int main(){
	scanf("%d %d", &V, &E);
    for (int i = 0; i < E; ++i){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        Vec.push_back(Edge(a, b, w));
    }

    int MST = 0;
    int cnt = 0;
    sort(Vec.begin(), Vec.end(), cmp);

    for (int i = 0; i < E; ++i){
        int a = Vec[i].A;
        int b = Vec[i].B;
        int aRoot = Find(a);
        int bRoot = Find(b);
        if (aRoot == bRoot) continue;
        Union(a, b);
        MST += Vec[i].W;
        Vec[i].Used = true;

        adj[a].push_back(pii(b, Vec[i].W));
        adj[b].push_back(pii(a, Vec[i].W));
        cnt++;
        if (cnt == V - 1) break;
    }

    if (cnt != V - 1 || E <= V - 1){
        printf("-1\n");
        return 0;
    }

    Depth[1] = 1;
    MakeDepth(1);
    for (int k = 0; k <= DMAX; ++k){
        for (int i = 1; i <= V; ++i){
            int Father = parent[i][k];
            if (Father && parent[Father][k] != 0){
                int w1 = Biggest[i][k].first;
                int w2 = Biggest[i][k].second;

                int f1 = Biggest[Father][k].first;
                int f2 = Biggest[Father][k].second;

                if (w1 > f1){
                    Biggest[i][k + 1].first = w1;
                    Biggest[i][k + 1].second = max(f1, w2);
                }
                else if (w1 < f1) {
                    Biggest[i][k + 1].first = f1;
                    Biggest[i][k + 1].second = max(w1, f2);
                }
                else Biggest[i][k + 1] = pii(w1, max(w2, f2));

                parent[i][k + 1] = parent[Father][k];
            }
        }
    }

    int Plus = INF;
    for (int i = 0; i < E; ++i){
        if (Vec[i].Used) continue;
        int t = HowAboutThis(Vec[i]);
        if (t == -1 || t == Vec[i].W) continue;
        Plus = min(Plus, Vec[i].W - t);
    }
    if (Plus == INF) printf("-1\n");
    else printf("%d\n", MST + Plus);
    return 0;
}
