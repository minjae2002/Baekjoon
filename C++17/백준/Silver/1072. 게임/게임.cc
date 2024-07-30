#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 1000000000
long long X, Y;		//확률 계산 시 100을 곱하면 int형 범위를 벗어나므로 long long형으로 선언 

bool fmin(int v){
	//v회 게임을 더 진행했을 때 승률이 오르는지 확인 
	if(Y * 100 / X < (Y + v) * 100 / (X + v)) return true;
	else return false;
}

int main(void){
	
	int lb = 0, ub = MAXSIZE, m;
	scanf("%lld %lld", &X, &Y);
	//애초에 승률이 99% 이상이라면, 소숫점은 버려지므로 승률은 변할 수 없다. 
	if(Y * 100 / X >= 99){
		printf("-1");
		return 0;
	}
	//Parametric Search
	while (lb + 1 < ub){
		m = lb + (ub - lb) / 2;
		if (fmin(m)) ub = m;
		else lb = m;
	}
	
	printf("%d", ub);
	
	return 0;
}