#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 10005;  //'005;

vector<int> adj[N];
int ans[N];

int dfn[N], low[N];
int num = 0, cnt = 0, root = -1;

void dfnlow(int node, int prev) {
    dfn[node] = low[node] = num++;
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (next == prev) continue;
        if (dfn[next] < 0) {
            dfnlow(next, node);
            low[node] = min(low[node], low[next]);
            if (low[next] >= dfn[node] && node != root) {  // 단절점
                ans[node] = 1;                             // u의 자식을 확인할 때 마다 push하므로 중복이 존재할 수 있다.
            }
            if (node == root) cnt++;
        } else {
            low[node] = min(low[node], dfn[next]);  //  w가 이미 방문한 곳(부모/조상)라면, 부모/조상의 dfn값을 가져온다.
        }
        // 이미 (low[node] = dfn[next]) < dfn[node]
        // dfn[next]보다 작은 값을 가져올 필요가 없음.
        // dfn[next]로 설정하는 것 만으로도 충분하다
        // low[dfn[next]]는 불가능하다 -> 아직 구해지지 않았음.
    }
}

int main(void) {
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));

    for (int i = 1; i <= v; i++) {  // 입력으로 주어지는 그래프는 연결 그래프가 아닐 수 있다
        if (dfn[i] < 0) {
            cnt = 0, num = 0;
            root = i;
            dfnlow(root, -1);
            if (cnt > 1) ans[root] = 1;  // root의 경우 자식의 개수가 2개 이상이면 단절점이다.
        }
    }

    int sz = 0;
    for (int i = 1; i <= v; i++) {
        if (ans[i] == 1) sz++;
    }
    cout << sz << "\n";
    for (int i = 1; i <= v; i++)
        if (ans[i] == 1) cout << i << " ";
    cout << "\n";
    return 0;
}