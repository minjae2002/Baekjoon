#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

bool Visit[MAXN];								// 소수 여부를 기록하는 배열. 초기는 모두 false
bool check(int &cnt, int &K, int &i){						// cnt: 현재까지 체에서 삭제된 수, K: 찾아야하는 순번, i: 현재 확인 중인 수 
	if (++cnt == K){							// cnt를 증가시키며, K와 같은지 비교 
		printf("%d", i);						// K와 같다면 현재 숫자 i를 출력 
		return true;							// K번째 삭제된 숫자를 찾았음을 표시. 
	}
	Visit[i] = true;							// cnt != K이더라도 현재 숫자 i는 배열에서 삭제. 
	
	return false;								// K번째 삭제된 수를 못 찾았다면 false. 
}

int main(){
	int N, K = 0, cnt = 0;
	scanf("%d %d", &N, &K);
	
	for (int i = 2; i <= N; i++){
		if (Visit[i]) continue;						// Visit[i] = true라면 이미 체에서 삭제한 수라는 뜻. continue를 통해 루프의 다음 반복으로 넘어감. 
		else if (check(cnt, K, i)) return 0;				// Visit[i] = false라면 아직 삭제되지 않은 수. 이게 K번째 삭제될 수인지 check한다. 
		
		for (int j = i * i; j <= N; j += i){				// i의 배수들에 대하여 
			if (!Visit[j] && check(cnt, K, j)) return 0;		// !Visit[i] (아직 삭제되지 않음) && check(cnt, K, j) = 1 (K번째 숫자 찾음) -> 프로그램 종료 
		}
	}
	return 0;
}
