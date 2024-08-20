#include <bits/stdc++.h>
using namespace std;
#define MAXN 51
#define INF 1e9
typedef pair<int, int> edge;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int room[MAXN][MAXN];
int cnt[MAXN][MAXN];

void input(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        char str[MAXN];
        scanf("%s", str);
        for (int j = 0; j < n; j++){
            room[i][j] = 1 - (str[j] - '0');
        }
    }
}

void bfs() {
    for(int i = 0; i < n; i++)
        fill(cnt[i], cnt[i] + n, INF);
    
    queue<edge> q;
    q.push(make_pair(0, 0));
    cnt[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (cnt[nx][ny] > cnt[x][y] + room[nx][ny]) {
                    cnt[nx][ny] = cnt[x][y] + room[nx][ny];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    input();
    bfs();
    printf("%d\n", cnt[n - 1][n - 1]);

    return 0;
}