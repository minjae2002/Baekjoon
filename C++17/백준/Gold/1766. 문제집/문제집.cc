#include <bits/stdc++.h>
using namespace std;
#define MAXN 32001

vector<int> order[MAXN];
int indeg[MAXN];

int main(){
	int N, M;
	scanf("%d %d", &N, &M); 
	
	while (M--){
		int A, B;
		scanf("%d %d", &A, &B);
		order[A].push_back(B);
		indeg[B]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> prob;
	for (int i = 1; i <= N; i++){
		if(!indeg[i]) prob.push(i);
	}
	
	while (!prob.empty()){
		int cur = prob.top();
		prob.pop();
		printf("%d ", cur);
		
		for (auto next : order[cur]){
			indeg[next]--;
			if (!indeg[next]) prob.push(next);
		}
	}
	return 0;
}
