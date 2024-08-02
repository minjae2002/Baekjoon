#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

bool Visit[MAXN];
bool check(int &cnt, int &K, int &i){
	if (++cnt == K){
		printf("%d", i);
		return true;
	}
	Visit[i] = true;
	
	return false;
}

int main(){
	int N, K = 0, cnt = 0;
	scanf("%d %d", &N, &K);
	
	for (int i = 2; i <= N; i++){
		if (Visit[i]) continue;
		else if (check(cnt, K, i)) return 0;
		
		for (int j = i * i; j <= N; j += i){
			if (!Visit[j] && check(cnt, K, j)) return 0;
		}
	}
	return 0;
}