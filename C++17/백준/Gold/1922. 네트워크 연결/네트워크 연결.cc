#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int N, M, Answer;																			// Answer = 컴퓨터 연결하며 드는 비용 
int parent[MAX];
vector<pair<int, pair<int, int>>> Edge;														// <비용, <컴퓨터1, 컴퓨터2>> 

void input(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Edge.push_back(make_pair(c, make_pair(a, b))); 
	}
}

int Find(int x){
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if (x != y) parent[y] = x;
}

bool sameParent(int x, int y){
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;	
}

void Solution(){
	sort(Edge.begin(), Edge.end());															// 비용으로 내림차순 정렬이 기본!
	for (int i = 1; i <= N; i++) parent[i] = i;												// 초기화
	for (int i = 0; i < M; i++){
		if (sameParent(Edge[i].second.first, Edge[i].second.second) == false){			// 두 컴퓨터가 같은 그룹이 아니라는 뜻. 
			Union(Edge[i].second.first, Edge[i].second.second);
			Answer = Answer + Edge[i].first;
		}
	}
	
	printf("%d", Answer);
}

int main(void){
	input();
	Solution();
	
	return 0;
}