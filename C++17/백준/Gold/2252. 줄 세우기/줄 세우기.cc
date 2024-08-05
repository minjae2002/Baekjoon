#include <bits/stdc++.h>
using namespace std;

#define MAX 32001

vector<int> adj[MAX];
int indegree[MAX];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	while(m--){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (!indegree[i]) q.push(i);
	}
	
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		
		for (auto person : adj[cur]){
			indegree[person]--;
			if (!indegree[person]) q.push(person);
		}
	}
	
	return 0;	
}