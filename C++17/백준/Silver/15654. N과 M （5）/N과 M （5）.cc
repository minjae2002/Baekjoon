#include <bits/stdc++.h>
using namespace std;
#define MAXN 9

int N, M;
vector<int> node;
int arr[MAXN] = {0, };
bool visited[MAXN] = {0, };

void input(){
    scanf("%d %d", &N, &M);
    node.resize(N);

    for (int i = 0; i < N; i++){
        scanf("%d", &node[i]);
    }
}

void dfs(int cnt){
    if (cnt == M){
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++){
        if (!visited[i]){
            visited[i] = true;
            arr[cnt] = node[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    input();
    sort(node.begin(), node.end());
    dfs(0);

    return 0;
}