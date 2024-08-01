// 그냥 배열로 하니까 시간 초과되므로 Fenwick Tree 사용 
#include <bits/stdc++.h>  
using namespace std;

#define MAXN 100002
typedef long long ll;

ll Ftree[MAXN];
int N, Q;

void update(int y, ll v){
    while(y <= N){
        Ftree[y] += v;
        y += (y & -y);
    }
}

ll getSum(int v){
    ll ret = 0;
    while(v > 0){
        ret += Ftree[v];
        v -= (v & -v);
    }
    return ret;
}

int main(){
    scanf("%d %d", &N, &Q);

    ll num, diff;
    for(int i = 1; i <= N; i++){
        scanf("%lld", &num);
        update(i, num);
    }

    for(int i = 0, x, y, a, b; i < Q; i++){
        scanf("%d %d %d %d", &x, &y, &a, &b);
        printf("%lld\n", getSum(max(x, y)) - getSum(min(x, y) - 1));
        diff = b - (getSum(a) - getSum(a-1));
        update(a, diff);
    }
    return 0;
}
