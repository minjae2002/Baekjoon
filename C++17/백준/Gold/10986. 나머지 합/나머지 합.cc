#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<int> num = {0,};

ll Comb(ll n){

    if (n == 0 || n == 1) return 0;
    return n * (n - 1) / 2;
}

void input(){
    scanf("%d %d", &N, &M);
    num.resize(N + 1);
    for (int i = 0; i < N; i++){
        ll A;
        scanf("%lld", &A);
        if (i == 0) A %= M;
        else A = (A + num[i - 1]) % M;

        num[i] = A;
    }
}

ll Solve(){
    ll sum = 0;
    sort(num.begin(), num.end());
    for (int i = 0; i < M; i++){
        ll t = upper_bound(num.begin(), num.end(), i) - lower_bound(num.begin(), num.end(), i);
        sum += Comb(t);
    }

    return sum;
}

int main(){

    input();
    ll ans = Solve();
    printf("%lld", ans);

    return 0;
}