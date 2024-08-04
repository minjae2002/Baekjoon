#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N;
	scanf("%d", &N);
	
	if (N == 1) return 0;
	
	int i = 2;
	while (N >= i){
		if (N % i == 0){
			printf("%d\n", i);
			N /= i;
		}
		else i++;
	}
	return 0;
}