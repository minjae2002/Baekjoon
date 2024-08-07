#include <bits/stdc++.h>
using namespace std;

int n, m;					// 숫자 개수 n, 연산 횟수 m 

int main(){
	scanf("%d %d", &n, &m);
	int arr[n + 1];
	int accum[n + 1];
	
	for (int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	accum[0] = 0;
	accum[1] = arr[1];
	for (int i = 2; i <= n; i++){
		accum[i] = accum[i - 1] + arr[i];
	}
	
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int ret;
		ret = accum[b] - accum[a - 1];
		printf("%d\n", ret);
	}
	return 0;
}