#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll mod(ll a, ll m) {
  return ((a%m) + m) % m;
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a/b;
    tie(a, b) = make_tuple(b, a%b);
    tie(x, xx) = make_tuple(xx, x-q*xx);
    tie(y, yy) = make_tuple(yy, y-q*yy);
  }
  return a;
}

ll modInverse(ll b, ll m) {           
  ll x, y;
  ll d = extEuclid(b, m, x, y);           
  if (d != 1) return -1;                      
 
  return mod(x, m);
}

int main(void){
	ll N;
	ll A, B, C;
	scanf("%lld %lld", &N, &A);
	
	B = N - A;
	C = modInverse(A, N);
	
	printf("%lld %lld", B, C);
	return 0;
}