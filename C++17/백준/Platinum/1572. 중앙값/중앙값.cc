#include <bits/stdc++.h>

using namespace std;

const int MAX = 65536;
int N, K;

vector<int> tree(4*MAX, 0);

void update(int start, int end, int idx, int diff, int node) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start == end) return;
    update(start, (start+end)/2, idx, diff, node*2);
    update((start+end)/2+1, end, idx, diff, node*2+1);
}

int getmid(int start, int end, int midx, int node) {
    if (start == end) {
        return start;
    }
    if (tree[node*2] < midx) {
        return getmid((start+end)/2+1, end, midx-tree[node*2], node*2+1);
    }
    else {
        return getmid(start, (start+end)/2, midx, node*2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    int midx = K/2+1;
    if (K%2 == 0) midx--;
    int x;
    long long ans = 0;
    queue<int> q;
    for (int i = 0; i < K; i++) {
        cin >> x;
        q.push(x);
        update(0, MAX-1, x, 1, 1);
    }
    ans += getmid(0, MAX-1, midx, 1);
    for (int i = K; i < N; i++) {
        update(0, MAX-1, q.front(), -1, 1);
        q.pop();
        cin >> x;
        q.push(x);
        update(0, MAX-1, x, 1, 1);
        ans += getmid(0, MAX-1, midx, 1);
    }
    cout << ans;
    return 0;
}