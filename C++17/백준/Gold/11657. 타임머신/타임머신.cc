#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define MAX 510
#define INF 987654321
typedef long long ll;
using namespace std;

int N, M;
ll Dist[MAX];
vector<pair<pair<int, int>, int>> Edge;

void Input(){
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) Dist[i] = INF;
    for (int i = 0; i < M; i++){
        int From, To, Cost;
        scanf("%d %d %d", &From, &To, &Cost);
        Edge.push_back(make_pair(make_pair(From, To), Cost));
    }
}

void Solution(){
    Dist[1] = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 0; j < Edge.size(); j++){
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;

            if (Dist[From] == INF) continue;
            if (Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
        }
    }

    for (int i = 0; i < Edge.size(); i++){
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;

        if (Dist[From] == INF) continue;
        if (Dist[To] > Dist[From] + Cost){
            printf("-1\n");
            return;
        }
    }

    for (int i = 2; i <= N; i++){
        if (Dist[i] == INF) printf("-1\n");
        else printf("%d\n", Dist[i]);
    }
}

void Solve(){
    Input();
    Solution();
}

int main(void){
    Solve();

    return 0;
}