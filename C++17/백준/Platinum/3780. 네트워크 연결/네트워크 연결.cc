#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
#define MAXN 20001

int T, N;
int parent[MAXN];                                                   // parent[x]는 x가 속한 클러스터의 센터 번호
int dist[MAXN];                                                     // dist[x]는 x에서 클러스터의 센터까지의 누적 거리

int find(int x){                                                    // 경로 압축을 통해 x와 x가 속한 클러스터의 센터 사이 거리 출력
    if (parent[x] == x) return x;
    int root = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = root;
}

void unite(int x, int y){                                           // x를 y에 병합
    parent[x] = y;
    dist[x] = abs(x - y) % 1000;
}

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);

        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
            dist[i] = 0;
        }
        
        while (true){
            char c;
            scanf(" %c", &c);
            if (c == 'O'){
                break;
            } else if (c == 'E'){
                int a;
                scanf("%d", &a);
                find(a);
                printf("%d\n", dist[a]);
            } else if (c == 'I'){
                int a, b;
                scanf("%d %d", &a, &b);
                unite(a, b);
            }
        }
    }
    return 0;
}