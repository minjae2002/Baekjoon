// 입력된 수열들 중 인접한 원소들끼리 몇 개가 더해지더라도 M이 될 수 있는 경우의 수 출력 

#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	
	int A[MAXN];
	
	for (int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	// 2 포인터
	int L = 0, R = 0, sum = 0, cnt = 0;
	
	while (R < N){
		sum += A[R];
		
		while (sum > M && L <= R){
			sum -= A[L++];
		}
		
		if (sum == M) cnt++;
		
		R++;
	}
	printf("%d", cnt);
	return 0;
}