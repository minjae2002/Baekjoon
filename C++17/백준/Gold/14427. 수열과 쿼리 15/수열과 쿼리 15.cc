#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define INF 987654321

int N, M, B;
pair<int, int> minIDT[2 * MAXN];

void buildTree(){  
    for (int i = 0; i < 2 * B; i++) {
        minIDT[i] = make_pair(INF, 0);
    }
    for (int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        minIDT[B + i] = make_pair(num, i + 1);
    }
    for (int j = B - 1; j > 0; j--){
        if (minIDT[2 * j].first > minIDT[2 * j + 1].first) minIDT[j] = minIDT[2 * j + 1];
        else minIDT[j] = minIDT[2 * j];
    }
}

void update(int i, int v){
    int idx = B + i -1;
    minIDT[idx] = make_pair(v, i);
    while (idx >= 1){
        idx /= 2;
        if (minIDT[2 * idx].first > minIDT[2 * idx + 1].first) minIDT[idx] = minIDT[2 * idx + 1];
        else minIDT[idx] = minIDT[2 * idx];
    }
}

void query(){
    int com;
    scanf("%d", &com);
    if (com == 1){
        int i, v;
        scanf("%d %d", &i, &v);
        update(i, v);
    } else if (com == 2){
        int ans = minIDT[1].second;
        printf("%d\n", ans);
    }
}

int main(){
    scanf("%d", &N);
    B = 1;                                                  // 리프 노드 개수 및 리프 노드의 시작 인덱스.
    while (B < N) B *= 2;
    buildTree();
    scanf("%d", &M);
    while(M--){
        query();
    }

    return 0;
}