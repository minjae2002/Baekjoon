#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, K;
bool visited[MAX];

int bfs(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;           // 시간, 위치
    q.push(make_pair(0, N));
    visited[N] = true;
    while (!q.empty()){
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if (x == K) return time;
        if (x * 2 < MAX && !visited[x * 2]){
            q.push(make_pair(time, x * 2));
            visited[x * 2] = true;
        } 
        
        if (x + 1 < MAX && !visited[x + 1]){
            q.push(make_pair(time + 1, x + 1));
            visited[x + 1] = true;
        }

        if (x - 1 >= 0 && !visited[x - 1]){
            q.push(make_pair(time + 1, x - 1));
            visited[x - 1] = true;
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs());
    return 0;
}