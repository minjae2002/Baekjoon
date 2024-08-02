/*
Range of the obstacle

start point    -> +1
end point + 1  -> -1
*/

// Prefix Sum
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define MAXH 500001

int N, H, MinHuddle, MinCnt;
int Cnt[MAXH];

int main(){
    MinHuddle = MAXN;								// 개똥벌레가 파괴해야 하는 장애물의 최소 개수 
    scanf("%d %d", &N, &H);
    int d;
    for(int i = 0; i < N; i++){
        scanf("%d", &d);
        if((i & 1) == 0){							// 장애물의 위치가 짝수인 경우  
            Cnt[0]++;								// 그 높이부터 d까지의 장애물 범위에 대해 개수 증가, 
            Cnt[d]--;								// d 이후에는 감소시킨다. (Prefix Sum) 
        } else {									// 위치가 홀수인 경우 
            Cnt[H - d]++;							// H - d 위치에서부터 개수 증가 
        }
    }
    
    int cntTemp = 0;								// 높이별 장애물 수를 누적합 방식으로 계산 
    for(int i = 0; i < H; i++){
        cntTemp += Cnt[i];
        if(cntTemp < MinHuddle){					// 기존 최소값보다 더 낮다면 
            MinHuddle = cntTemp;					// 최솟값을 변경하고 
            MinCnt = 1;								// 최솟값의 개수를 초기화 
        } else if(cntTemp == MinHuddle){			// 기존 최소값과 같다면 
            MinCnt++;								// 개수만 1 증가시킨다 
        }
    }   
    
    printf("%d %d\n", MinHuddle, MinCnt);

    return 0;
}
