#include <bits/stdc++.h>
using namespace std;
#define MAXN 9

int N, M;
int node[MAXN];
int arr[MAXN];
bool visited[MAXN];

void input(){
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++){
        scanf("%d", &node[i]);
    }

    sort(node, node + N);
}

void func(int cnt){
    if (cnt == M){
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++){
        if (!visited[i] && tmp != node[i]){
            arr[cnt] = node[i];
            tmp = node[i];
            visited[i] = true;
            func(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    input();
    func(0);

    return 0;
}