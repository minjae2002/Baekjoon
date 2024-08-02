#include <bits/stdc++.h>
using namespace std;

#define MAXN 4000001
typedef long long ll;

bool Visit[MAXN];
int Prime[MAXN];

int main(){
	int N, primeCnt = 0;
	scanf("%d", &N);
	
	for (int i = 2; i <= N; i++){
		if (Visit[i]) continue;
		Prime[primeCnt++] = i;
		
		for(ll j = (ll)i * i; j <= N; j += i) Visit[j] = true;
	}
	
	int l = 0, r = 0, sum = 0, cnt = 0;
	
	while(true){
		if (sum >= N) sum -= Prime[l++];
		else if (r == primeCnt) break;
		else sum += Prime[r++];
		
		if (sum == N) cnt++;
	}
	printf("%d", cnt);
	return 0;
}