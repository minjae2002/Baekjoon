#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue<int> A; 

int main(void){
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++){
		ll x;
		scanf("%lld", &x);
		
		if (x != 0){
			A.push(-x);
		} 
		else {
			if (A.empty()) printf("0\n");
			else {
				ll a = -A.top();
				printf("%lld\n", a);
				A.pop();
			}
		}
	}
	return 0;
}