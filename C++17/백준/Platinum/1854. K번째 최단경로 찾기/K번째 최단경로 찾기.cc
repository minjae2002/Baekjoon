#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
typedef pair<int, int> Node;
int n, m, k;
int W[MAXN][MAXN];
priority_queue<int> distQ[MAXN];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++){
        int a, b, c;                                // a에서 b까지 가는 데 c의 시간 소요.
        scanf("%d %d %d", &a, &b, &c);
        W[a][b] = c;
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));
    distQ[1].push(0);

    while (!pq.empty()){
        Node u = pq.top();
        pq.pop();

        for (int adjNode = 1; adjNode <= n; adjNode++){
            if (W[u.second][adjNode] != 0){
                if (distQ[adjNode].size() < k){
                    distQ[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                } else if (distQ[adjNode].top() > u.first + W[u.second][adjNode]){
                    distQ[adjNode].pop();
                    distQ[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (distQ[i].size() == k) printf("%d\n", distQ[i].top());
        else printf("-1\n");
    }

    return 0;
}