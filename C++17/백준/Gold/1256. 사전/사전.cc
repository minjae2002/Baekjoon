#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXK 1000000000

int DP[MAXN * 2 + 1][MAXN + 1];

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	n += m;
	
	DP[0][0] = 1;
	for (int i = 1; i <= n; i++){
		DP[i][0] = 1;
		for (int j = 1; j <= i && j <= m; j++){
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
			// overflow 발생 주의 필요.
			if(DP[i][j] > MAXK) DP[i][j] = (MAXK + 1); 
		}
	}
	
	if (DP[n][m] < k){
		printf("-1");
		return 0;
	}
	
	while(n){
		if (DP[n - 1][m] >= k) printf("a");
		else{
			printf("z");
			k -= DP[n - 1][m--];
		}
		n--;
	}
	return 0;
}