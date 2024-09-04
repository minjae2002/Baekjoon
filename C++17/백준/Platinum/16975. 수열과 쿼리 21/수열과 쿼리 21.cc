#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long ll;

int N, M;
vector<ll> A, D;

void update(int l, int r, ll k) {
    D[l] += k;
    if (r + 1 <= N) D[r + 1] -= k;
}

ll getValue(int x) {
    ll result = A[x];
    for (int i = 1; i <= x; i++) {
        result += D[i];
    }
    return result;
}

int main() {
    scanf("%d", &N);
    A.resize(N + 1, 0);
    D.resize(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        if (num == 1) {
            int a, b;
            ll c;
            scanf("%d %d %lld", &a, &b, &c);
            update(a, b, c);
        } else if (num == 2) {
            int x;
            scanf("%d", &x);
            printf("%lld\n", getValue(x));
        }
    }
    return 0;
}
