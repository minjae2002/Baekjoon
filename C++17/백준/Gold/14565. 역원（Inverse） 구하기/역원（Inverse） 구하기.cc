#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll mod(ll a, ll m) {						// a (mod m) 반환 
  return ((a % m) + m) % m;					// 값이 음수 나오는 것 방지 
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {	// 확장된 유클리드 호제법 
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a / b;
    tie(a, b) = make_tuple(b, a % b);
    tie(x, xx) = make_tuple(xx, x - q * xx);
    tie(y, yy) = make_tuple(yy, y - q * yy);
  }
  return a;
}

ll modInverse(ll b, ll m) {           		// 곱셈 역원 계산 
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
