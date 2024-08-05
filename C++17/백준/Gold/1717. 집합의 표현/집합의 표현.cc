#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
int parent[MAXN];

// 자꾸 시간 초과가 뜨므로 Rank를 만들자.
int Rank[MAXN] = {1,}; 										// 자신과 같은 그룹의 원소 개수 

int find(int a){
	if (parent[a] == a) return a;
	else return find(parent[a]);
}

void uniongraph(int a, int b){
	int aRoot = find(a);
	int bRoot = find(b);
	
	if (Rank[aRoot] > Rank[bRoot]){
		parent[aRoot] = bRoot;
		Rank[bRoot] += Rank[aRoot];
		Rank[aRoot] = Rank[bRoot];		
	}
	else {
		parent[bRoot] = aRoot;
		Rank[aRoot] += Rank[bRoot];
		Rank[bRoot] = Rank[aRoot];
	}
	
} 

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= n; i++){					// 원소를 1개씩 가지는 서로소 집합 n + 1개 생성. 
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++){					// 총 m번의 연산 쿼리 입력.
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		
		if (q == 0){
			uniongraph(a, b);
		} else if (q == 1){
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}