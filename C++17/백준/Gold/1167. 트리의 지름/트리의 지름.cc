#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;
vector<vector<Edge>> A;
vector<bool> visited;
vector<int> m_distance;

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    visited[node] = true;

    while (!Q.empty()){
        int now_node = Q.front();
        Q.pop();
        for (Edge i : A[now_node]){
            if (!visited[i.first]){
                visited[i.first] = true;
                Q.push(i.first);
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    A.resize(N + 1);

    for (int i = 1; i <= N; i++){
        int S;
        scanf("%d", &S);
        while (true){
            int E, V;
            scanf("%d", &E);
            if (E == -1) break;
            scanf("%d", &V);
            A[S].push_back(Edge(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    BFS(1);
    int MAX = 1;

    for (int i = 2; i <= N; i++){
        if (m_distance[MAX] < m_distance[i]) MAX = i;
    }

    fill(m_distance.begin(), m_distance.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(MAX);
    sort(m_distance.begin(), m_distance.end());

    printf("%d", m_distance[N]);

    return 0;
}