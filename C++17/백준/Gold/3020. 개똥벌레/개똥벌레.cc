/*
// prefix sum 방식 사용 

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAXN 200000
#define INF 500000

// 특정 높이를 지나는 장애물의 수 cnt 
int cnt[MAXN];

int main(void){
	int N, H;
	scanf("%d %d", &N, &H);

	int height;
	for (int i = 0; i < N; i++){
		scanf("%d", &height);
		if (i % 2 == 0){
			cnt[0] += 1;
			cnt[height] -= 1;
		}
		else {
			cnt[H - 1] += 1;
			cnt[H - height - 1] -= 1;
		}
	}

	int minHuddle = INF;
	int minCnt = 0;
	
	for (int i = 0; i < H; i++){
		if (cnt[i] < minHuddle){
			minHuddle = cnt[i];
			minCnt++;
		}
		
	}

	return 0;
} */

/*
Range of the obstacle

start point    -> +1
end point + 1  -> -1
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001
#define MAXH 500001

int N, H, MinHuddle, MinCnt;
int Cnt[MAXH];

int main()
{
    MinHuddle = MAXN;
    scanf("%d %d", &N, &H);
    int d;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &d);
        if((i&1) == 0)
        {
            Cnt[0]++;
            Cnt[d]--;
        }
        else
        {
            Cnt[H-d]++;
        }
    }
    
    int cntTemp = 0;
    for(int i = 0; i < H; i++)
    {
        cntTemp += Cnt[i];
        if(cntTemp < MinHuddle)
        {
            MinHuddle = cntTemp;
            MinCnt = 1;
        }
        else if(cntTemp == MinHuddle)
        {
            MinCnt++;
        }
    }   
    
    printf("%d %d\n", MinHuddle, MinCnt);

    return 0;
}