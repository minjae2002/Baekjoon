#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF INT_MAX

int maze[MAX][MAX];
int cnt[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;

void input(){
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++){
        char str[MAX]; 
        scanf("%s", str);
        for (int j = 0; j < M; j++){
            cnt[i][j] = INF;
            maze[i][j] = str[j] - '0'; 
        }
    }
}

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    cnt[0][0] = 0;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= N || newy < 0 || newy >= M) continue;
            if (maze[newx][newy] == 1){
                if (cnt[newx][newy] > cnt[x][y] + 1){
                    cnt[newx][newy] = cnt[x][y] + 1;
                    q.push(make_pair(newx, newy));
                }
            } else if (maze[newx][newy] == 0){
                if (cnt[newx][newy] > cnt[x][y]){
                    cnt[newx][newy] = cnt[x][y];
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }
}

int main(){
    input();
    bfs();

    printf("%d\n", cnt[N - 1][M - 1]);

    return 0;
}