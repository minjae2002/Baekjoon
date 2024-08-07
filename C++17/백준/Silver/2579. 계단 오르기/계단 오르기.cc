#include <bits/stdc++.h>
using namespace std;

#define MAXN 301
int N, score[MAXN];
int table[3][MAXN] = {0,};										// 0행의 경우 전체 경우의 수 중 최대 점수, 1행의 경우 직전에 1칸 온 경우, 2행의 경우 직전에 2칸 온 경우. 

void input(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &score[i]);
	}
}

void tablefit(){
	for (int j = 1; j <= N; j++){
		table[1][j] = table[2][j - 1] + score[j];
		table[2][j] = table[0][j - 2] + score[j];
		table[0][j] = max(table[1][j], table[2][j]); 
	}
}

int main(void){
	input();
	tablefit();
	int ans = table[0][N];
	printf("%d", ans);
	return 0;
}