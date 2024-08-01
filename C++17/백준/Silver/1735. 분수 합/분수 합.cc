#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int up[2];
int down[2];

int main(void){
	for (int i = 0; i < 2; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		up[i] = a;
		down[i] = b;
	}
	
	int fUp = up[0] * down[1] + up[1] * down[0];
	int fDown = down[0] * down[1];
	
	int GCDUD = __gcd(fUp, fDown);
	
	fUp = fUp / GCDUD;
	fDown = fDown / GCDUD;
	
	printf("%d %d", fUp, fDown);
	return 0;
}