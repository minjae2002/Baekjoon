// 상대는 내 점수를 최소화하기 위해 노력한다. 
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int T, N;
int card[MAX];
int dp[MAX][MAX];

int Solve(int l, int r){
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];
	
	if ((N - r + l) % 2 != 0){																// 근우 차례 -> 근우의 점수를 최대화하고자 함. 
		return dp[l][r] = max(card[l] + Solve(l + 1, r), card[r] + Solve(l, r - 1));
	} else {																				// 명우 차례 -> 근우의 점수를 최소화하고자 함.
		return dp[l][r] = min(Solve(l + 1, r), Solve(l, r - 1));
	}
}

int main(void){
	scanf("%d", &T);
	while (T--){
		memset(card, 0, sizeof(card));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		for (int j = 1; j <= N; j++){
			scanf("%d", &card[j]);
		}
		printf("%d\n", Solve(1, N));
	}
	return 0;
}

