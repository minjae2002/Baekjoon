#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int N, M, K, B;
vector<ll> tree;

void buildTree() {
    scanf("%d %d %d", &N, &M, &K);

    B = 1;
    while (B < N) B *= 2;

    tree.resize(2 * B, 1);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &tree[B + i]);

    }

    for (int i = B - 1; i > 0; i--) {
        tree[i] = (tree[2 * i] * tree[2 * i + 1]) % MOD;
    }
}

void update(int i, int newValue) {
    int idx = B + i;
    tree[idx] = newValue;

    while (idx > 1) {
        idx /= 2;
        tree[idx] = (tree[2 * idx] * tree[2 * idx + 1]) % MOD;
    }
}

ll mul(int start, int end) {
    int L = B + start - 1;
    int R = B + end - 1;
    ll ret = 1;
    while (L <= R) {
        if (L % 2 == 1) {
            ret = (ret * tree[L]) % MOD;
            L++;
        }
        if (R % 2 == 0) {
            ret = (ret * tree[R]) % MOD;
            R--;
        }
        L /= 2;
        R /= 2;
    }
    return ret;
}

int main(void) {
    buildTree();
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        ll ans = 1;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            update(b - 1, c);
        } else if (a == 2) {
            ans = mul(b, c);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
