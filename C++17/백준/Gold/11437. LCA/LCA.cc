#include <bits/stdc++.h>
using namespace std;
#define MAXN 50001

int n, m;
int visited_dfs[MAXN];
vector<int> Depth(MAXN, -1);
vector<vector<int>> parent(MAXN, vector<int>(17, 0));
vector<int> edge[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

void findDepth(int S) {
    for (int next : edge[S]) {
        if (Depth[next] == -1) {
            Depth[next] = Depth[S] + 1;
            parent[next][0] = S;
            findDepth(next);
        }
    }
}

int findLCA(int l, int r) {
    if (Depth[l] < Depth[r]) {
        swap(l, r);
    }
    int diff = Depth[l] - Depth[r];
    int j = 0;
    while (diff) {
        if (diff % 2) l = parent[l][j];
        j++;
        diff /= 2;
    }

    if (l != r) {
        for (int j = 16; j >= 0; j--) {
            if (parent[l][j] != parent[r][j]) {
                l = parent[l][j];
                r = parent[r][j];
            }
        }
        l = parent[l][0];
    }
    return l;
}

int main(void) {
    input();
    Depth[1] = 0;
    findDepth(1);

    for (int j = 0; j < 16; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j + 1] = parent[parent[i][j]][j];
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        int ans = findLCA(p, q);
        printf("%d\n", ans);
    }
    return 0;
}