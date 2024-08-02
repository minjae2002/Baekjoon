#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXK 1000000000

int DP[MAXN * 2 + 1][MAXN + 1];								// 동적 계획법 배열로, 특정 길이와 특정 개수의 'z'를 포함하는 문자열의 개수를 저장

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	n += m;													// 전체 문자열의 길이(N개의 a와 M개의 z를 더한 값)으로 갱신
	
	DP[0][0] = 1;											// 빈 문자열의 경우를 초기화
	for (int i = 1; i <= n; i++){
		DP[i][0] = 1;
		for (int j = 1; j <= i && j <= m; j++){
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];		// 첫 문자가 z인 경우 DP[i - 1][j - 1], 첫 문자가 a인 경우 DP[i - 1][j] 
			// overflow 발생 주의 필요.
			if(DP[i][j] > MAXK) DP[i][j] = (MAXK + 1); 
		}
	}
	
	if (DP[n][m] < k){										// DP[n][m] 값이 K보다 작다면 주어진 조건에서 K번째 문자열을 만들 수 없다는 의미.
		printf("-1");										// -1을 출력하고
		return 0;											// 프로그램을 종료
	}
	
	while(n){												// K번째 문자열을 만들기 위해 각 단계에서 a를 먼저 고려
		if (DP[n - 1][m] >= k) printf("a");					// DP[n-1][m]가 K보다 크거나 같다면 다음 문자로 a를 추가
		else{												// 그렇지 않다면 
			printf("z");									// z를 추가하고,  
			k -= DP[n - 1][m--];							// K에서 DP[n-1][m]을 빼고 m을 감소
		}
		n--;
	}
	return 0;
}
