#include <bits/stdc++.h>
#include <string>
using namespace std;

# define MAXN 100000

int main(){
	int N, S;
	scanf("%d %d", &N, &S);
	
	int buf[MAXN + 1];
	for (int i = 0; i < N; i++) scanf("%d", &buf[i]);
	
	int L = 0, R = 0, sum = 0, ans = N + 1;
	
	while(true){
		if (sum >= S){
			ans = min(ans, R - L);
			sum -= buf[L++];			//부분합이 S 이상인 경우 L 포인터가 가리키는 값을 빼고 포인터를 오른쪽으로 한 칸 이동
		}
		else if (R == N) break;
		else sum += buf[R++];			//부분합이 S 미만인 경우 R 포인터가 가리키는 갑을 더해주고 포인터를 오른쪽으로 한 칸 이동
	}
	
	printf("%d", ans == N + 1 ? 0 : ans);
	
	return 0; 
}