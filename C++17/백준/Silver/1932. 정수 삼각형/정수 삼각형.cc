#include <bits/stdc++.h>
using namespace std;

#define MAXN 501
int D[MAXN][MAXN] = {0,};
int n;

void input(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			int a;
			scanf("%d", &a);
			D[i][j] = a;
		}
	}
	for (int i = 1; i <= n; i++){
		D[i + 1][1] += D[i][1];
		D[i + 1][i + 1] += D[i][i];
		for (int j = 2; j <= i; j++){
			D[i + 1][j] += max(D[i][j], D[i][j - 1]);
		}
	}
}

int main(){
	input();
	int maxsum = 0;
	for (int j = 1; j <= n; j++) maxsum = max(maxsum, D[n][j]);
	printf("%d", maxsum);
	return 0;
}