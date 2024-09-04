#include <bits/stdc++.h>
using namespace std;
#define MAXN 9

int N, M;
int arr[MAXN] = {0, };
bool visited[MAXN] = {0, };

void dfs(int num, int cnt){
    if (cnt == M){
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = num; i <= N; i++){
        if (!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    dfs(1, 0);

    return 0;    
}