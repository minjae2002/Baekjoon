#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int main(void){
	int N;
	scanf("%d", &N);
	
	int maxsum[3] = {0,};										// 최대 점수 저장 
	int minsum[3] = {0,};										// 최소 점수 저장  
	int data[3] = {0,};											// 들어오는 값 저장
	int maxsumtmp[3] = {0,};
	int minsumtmp[3] = {0,};
	
	for (int i = 0; i < N; i++){								// i행 
		
		for(int j = 0; j < 3; j++){								// j열 
			int v;
			int maxtmp = 0, mintmp = 0;
			
			scanf("%d", &v);
			data[j] = v;										// data에 저장 
			
			if (i == 0){										// 첫 행의 경우 그 자체로 최대 점수이자 최소 점수 
				maxsumtmp[j] = v;
				minsumtmp[j] = v; 
			}
			else {
				if (j == 0){
					maxtmp = max(maxsum[j], maxsum[j + 1]);
					mintmp = min(minsum[j], minsum[j + 1]);
				}
				else if (j == 1){
					maxtmp = max(max(maxsum[j - 1], maxsum[j]), maxsum[j + 1]);
					mintmp = min(min(minsum[j - 1], minsum[j]), minsum[j + 1]);
				}
				else {
					maxtmp = max(maxsum[j - 1], maxsum[j]);
					mintmp = min(minsum[j - 1], minsum[j]);
				}
				
				maxsumtmp[j] = data[j] + maxtmp;
				minsumtmp[j] = data[j] + mintmp;				
			}
		}
		for (int i = 0; i < 3; i++){
			maxsum[i] = maxsumtmp[i];
			minsum[i] = minsumtmp[i];
		}
	}
	
	int MAX = 0, MIN = INF;
	for (int j = 0; j < 3; j++){
		MAX = max(MAX, maxsum[j]);
		MIN = min(MIN, minsum[j]);
	}
	printf("%d %d", MAX, MIN);
	return 0;
}