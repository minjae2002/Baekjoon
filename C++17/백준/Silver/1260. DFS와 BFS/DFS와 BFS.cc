#include <bits/stdc++.h>
using namespace std;

// adjacency list로 풀어보는 중.
vector<int> adj_list[1001];
bool visit_dfs[1001];
bool visit_bfs[1001];

void dfs(int cur){
	printf("%d ", cur);
	visit_dfs[cur] = true;
	for (int V : adj_list[cur]){
		if (!visit_dfs[V]) dfs(V);
	}
}

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	visit_bfs[cur] = true;
	while (!q.empty()){
		int cur_vtx = q.front();
		q.pop();
		printf("%d ", cur_vtx);
		for (int V : adj_list[cur_vtx]){
			if (!visit_bfs[V]){
				visit_bfs[V] = true;
				q.push(V);
			}
		}
	}
}

int main(void){
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	
	for (int i = 1; i <= M; i++){
		int S, D;
		scanf("%d %d", &S, &D);
		adj_list[S].push_back(D);
		adj_list[D].push_back(S);
	}
	
	for (int i = 1; i <= N; i++){
		sort(adj_list[i].begin(), adj_list[i].end());
	}
	
	dfs(V);
	printf("\n");
	bfs(V);
	return 0;	
}