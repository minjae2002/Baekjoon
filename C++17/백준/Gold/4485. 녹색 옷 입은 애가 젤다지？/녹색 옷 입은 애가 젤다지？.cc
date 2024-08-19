#include <bits/stdc++.h>
using namespace std;
#define MAX 126
#define INF 1e9

int N;
int cnt = 1;
int cave[MAX][MAX];
int loss[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(){
    for(int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            loss[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    loss[0][0] = cave[0][0];

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (loss[nx][ny] > loss[x][y] + cave[nx][ny]){
                loss[nx][ny] = loss[x][y] + cave[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    while (true){
        scanf("%d", &N);
        if (N == 0) break;
        memset(cave, INF, sizeof(cave));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d", &cave[i][j]);
            }
        }
        bfs();
        int ans = loss[N - 1][N - 1];
        printf("Problem %d: %d\n", cnt, ans);
        cnt++;
    }
    return 0;
}