#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MAX 501
int n, m, order;
vector <int> down[MAX];									// 나보다 작은 애들 저장 
vector <int> up[MAX];									// 나보다 큰 애들 저장 
int check[MAX];

void DFS(vector<int> v[], int start){
	check[start] = 1;
	for (int i = 0; i < v[start].size(); i++){
		int x = v[start][i];
		if (check[x] == 0){
			check[x] = 1;
			order++;
			DFS(v, x);
		}
	}
}

void solve(){
	int ans = 0;
	for (int i = 1; i <= n; i++){
		order = 0;
		memset(check, 0, sizeof(check));
		DFS(down, i);
		memset(check, 0, sizeof(check));
		DFS(up, i);
		if (order == n - 1) ans++;
	}
	printf("%d", ans);
}

int main(void){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		down[y].push_back(x);
		up[x].push_back(y);
	}
	solve();
	return 0;
}