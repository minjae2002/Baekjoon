#include <bits/stdc++.h>
using namespace std;

#define MAXN 15

bool Col[MAXN], Ld[MAXN*2], Rd[MAXN*2];
int N, Ans = 0;

void backtracking(int c)
{
    if(c==N)
    {
        Ans++;
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(Col[i] || Ld[i+c] || Rd[c-i+N-1]) continue;		// 이 줄이 이 코드의 핵심
        Col[i] = Ld[i+c] = Rd[c-i+N-1] = true;
        backtracking(c+1);
        Col[i] = Ld[i+c] = Rd[c-i+N-1] = false;
    }
}

int main()
{
    scanf("%d", &N);

    backtracking(0);

    printf("%d", Ans);
}