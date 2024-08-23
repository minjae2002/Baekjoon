#include <bits/stdc++.h>
using namespace std;
#define MAXN 501
typedef pair<int, int> edge;

int N;
int btime[MAXN];
int indegree[MAXN];
int result[MAXN];
vector<int> V[MAXN];

void input(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        scanf("%d", &btime[i]);
        while (1){
            int j;
            scanf("%d", &j);
            if (j == -1) break;
            V[j].push_back(i);
            indegree[i]++;
        }
    }
}

void Solve(){
    queue<int> q;
    for (int i = 1; i <= N; i++){
        if (indegree[i] == 0){
            q.push(i);
            result[i] = btime[i];
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto &p : V[cur]){
            int next = p;
            indegree[next]--;

            result[next] = max(result[next], result[cur] + btime[next]);
            if (indegree[next] == 0) q.push(next);
        }
    }
    for (int i = 1; i <= N; i++){
        printf("%d\n", result[i]);
    }
}

int main(){
    input();
    Solve();

    return 0;
}