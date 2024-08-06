#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 20010

int V, E, Start;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void input(){
	scanf("%d %d %d", &V, &E, &Start);
	for (int i = 0; i < E; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);		
		Vertex[a].push_back(make_pair(b, c));									// Vertex: a에서 b로 가는 경로의 가중치 c 
	}
	for (int i = 1; i <= V; i++) Dist[i] = INF;
}

void Solution(){
	priority_queue<pair<int, int>> PQ;											// pair(가중치, 노드) 
	PQ.push(make_pair(0, Start));
	Dist[Start] = 0;
	
	while (!PQ.empty()){
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();
		
		for (int i = 0; i < Vertex[Cur].size(); i++){
			int Next = Vertex[Cur][i].first;
			int nCost = Vertex[Cur][i].second;
			
			if (Dist[Next] > Cost + nCost){
				Dist[Next] = Cost + nCost;										// 더 짧은 경로라는 뜻이므로 값 업데이트
				PQ.push(make_pair(-Dist[Next], Next)); 
			} 
		}
	}
	
	for (int i = 1; i <= V; i++){
		if (Dist[i] == INF) printf("INF\n");
		else printf("%d\n", Dist[i]);
	}
}

int main(void){
	input();
	Solution();
	
	return 0;
}