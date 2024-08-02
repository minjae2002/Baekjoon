#include <bits/stdc++.h>
using namespace std;

int fac(int n){
	int ans = 1;
	for (int i = 1; i <= n; i++){
		ans *= i;
	}
	return ans;
}


int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	
	int ans;
	ans = fac(N) / (fac(K) * fac(N - K));
	printf("%d", ans);
	
	return 0; 
}