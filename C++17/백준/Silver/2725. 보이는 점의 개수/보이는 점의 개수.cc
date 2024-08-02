#include <bits/stdc++.h>
using namespace std;
// x와 y가 서로소여야 보이는 점. 
// 오일러피 함수와 DP 사용.

#define MAXN 1000

bool Visit[MAXN+1];														//소수:false, 소수 아님:true
int Prime[MAXN+1];
int DP[MAXN+1];
int PrimeCnt;

int eulerPhi(int n){													// 오일러 피 함수 
    // start from ans = N
    int ans = n;
    for(int i = 0; i < PrimeCnt && Prime[i] * Prime[i] <= n; i++){		// 루트n 이하의 소수만 확인하면 n의 소수 여부를 알 수 있음. 
        //count unique
        if (n % Prime[i] == 0) ans -= ans / Prime[i];					// Prime[i]가 n의 소인수라면 Prime[i]의 배수들 개수를 빼야 함. 
        // prime factor
        while (n % Prime[i] == 0) n /= Prime[i];						// n에서 Prime[i] 인수 제거 
    }
    // last factor
    if (n != 1) ans -= ans / n;											// n이 1이 아니라면 인수가 남아있다는 뜻이므로 n으로 나눠준다. 
    return ans;
}

int main(){
    for(int i = 2; i <= MAXN; i++){										// 에라토스테네스의 체를 이용하여 소수 체크 
        if(Visit[i]) continue;

        Prime[PrimeCnt++] = i;

        for(int j = i * i; j <= MAXN; j += i) Visit[j] = true;
    }

    DP[1] = 3;															// DP 배열 채우기 
    for(int i = 2; i <= MAXN; i++){	
        DP[i] = DP[i - 1] + eulerPhi(i) * 2;							// 각 i에 대해 새로운 좌표를 추가할 때 몇 개의 새로운 좌표가 보이는지를 계산
    }

    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", DP[N]);
    }

    return 0;
}
 
