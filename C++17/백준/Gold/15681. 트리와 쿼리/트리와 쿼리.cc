#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, R, Q, result;
vector<int> n[100001];
vector<int> q;
vector<int> tree[100001];
int treeSize[100001];

void createTree(int parent, int now) {
    for (int i = 0; i < n[now].size(); i++) {
        int next = n[now][i];

        if (parent == next) continue;

        tree[now].push_back(next);
        createTree(now, next);
    }
}

void findSize(int node) {
    treeSize[node] = 1;

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];

        findSize(next);
        treeSize[node] += treeSize[next];
    }
}

void solution() {
    createTree(0, R);
    findSize(R);

    for (int i = 0; i < q.size(); i++) {
        cout << treeSize[q[i]] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R >> Q;

    int U, V;
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        n[U].push_back(V);
        n[V].push_back(U);
    }

    int a;
    for (int i = 0; i < Q; i++) {
        cin >> a;
        q.push_back(a);
    }

    solution();

    return 0;
}