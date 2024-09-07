#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;
map <ll, ll> F;

ll fibo(ll n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (F.count(n) > 0) return F[n];

    if (n % 2 == 0){
        ll m = n / 2;
        ll tmp1 = fibo(m - 1);
        ll tmp2 = fibo(m);
        F[n] = ((2 * tmp1 + tmp2) * tmp2) % MOD;
        return F[n];
    }

    ll m = (n + 1) / 2;
    ll tmp1 = fibo(m - 1);
    ll tmp2 = fibo(m);
    F[n] = (tmp1 * tmp1 + tmp2 * tmp2) % MOD;
    return F[n];
}

int main(){
    scanf("%lld", &n);
    printf("%lld", fibo(n));

    return 0;
}