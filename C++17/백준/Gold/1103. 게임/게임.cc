#include <bits/stdc++.h>

using namespace std;

#define MAXN 51

int N, M, Ans;
char Data[MAXN][MAXN];
bool Visit[MAXN][MAXN];//방문 여부
int DP[MAXN][MAXN];//움직인 횟수 -> 일종의 cache

int dc[] = {-1, 0, 0, 1};	//column 이동 방향
int dr[] = {0, -1, 1, 0};	//row 이동 방향

bool dfs(int r, int c, int cnt)
{
    if(Ans==-1) return true;

    Ans = max(Ans, cnt);

    Visit[r][c] = true;		// cycle check를 위함
    DP[r][c] = cnt;

    for(int i=0; i<4; i++)
    {
        int nr = r + dr[i]*(Data[r][c]-'0');		//i에 따른 row 좌표 변화
        int nc = c + dc[i]*(Data[r][c]-'0');		//i에 따른 column 좌표 변화
        
        if(nr<0 || nr>=N || nc<0 || nc>=M || Data[nr][nc] == 'H') continue;

        if(Visit[nr][nc])
        {
            Ans = -1;
            return true;
        }

		//기존에 움직인 횟수보다 작으면 당연히 더 진행할 필요없다.(PRUNING)
        if (DP[nr][nc] > 0 && cnt < DP[nr][nc]) continue;

        if(dfs(nr, nc, cnt+1)) return true;
    }

    Visit[r][c] = false;
    return false;
}
 
int main()
{
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++) scanf("%s", Data[i]);

    dfs(0, 0, 1);
    printf("%d", Ans);
}
