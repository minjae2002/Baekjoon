#include <bits/stdc++.h>
using namespace std;

priority_queue<int> minheap;

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int A;
		scanf("%d", &A);
		minheap.push(-A); 
	}
	
	while (minheap.size() > 0){
		int N = minheap.top();
		printf("%d\n", -N);
		minheap.pop();
	}
	
	return 0;
} 