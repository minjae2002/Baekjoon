#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll distance2(ll x1, ll y1, ll x2, ll y2){
	ll xdiff = abs(x1 - x2);
	ll ydiff = abs(y1 - y2);

	return xdiff * xdiff + ydiff * ydiff;
}

int main(void){
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++){
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		ll cdist2 = distance2(x1, y1, x2, y2);
		
		int ans;
		
		if (cdist2 == 0){
			if (r1 == r2) ans = -1;
			else ans = 0;
		}
		else {
			if (cdist2 == (r1 + r2) * (r1 + r2) || cdist2 == abs(r1 - r2) * abs(r1 - r2)) ans = 1;
			else if (cdist2 < (r1 + r2) * (r1 + r2) && cdist2 > abs(r1 - r2) * abs(r1 - r2)) ans = 2;
			else ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}