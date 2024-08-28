#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int N, M, B = 1;
ll tree[MAXN] = {0,};
ll res[MAXN];
queue<pii> firstquery;
priority_queue<piiii, vector<piiii>, greater<>> secondquery;              // k순으로 정렬되는 pq

void init(){
    for (int i = B - 1; i > 0; i--){
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

void Q1(int i, int v){
    int idx = B + i - 1;
    ll diff = v - tree[idx];
    while (idx > 0){
        tree[idx] += diff;
        idx /= 2;
    }
}

ll Q2(int i, int j){
    int s = B + i - 1;
    int e = B + j - 1;
    ll sum = 0;
    while (s <= e){
        if (s % 2 == 1) sum += tree[s++];  // s가 홀수인 경우 현재 노드를 더하고 다음 노드로 이동
        if (e % 2 == 0) sum += tree[e--];  // e가 짝수인 경우 현재 노드를 더하고 이전 노드로 이동
        s /= 2;
        e /= 2;
    }
    return sum;
}

int main(){
    fill(res, res + MAXN, -1);
    scanf("%d", &N);
    while (B < N) B *= 2;

    for (int i = 0; i < N; i++){
        scanf("%lld", &tree[B + i]);
    }
    init();

    scanf("%d", &M);
    for (int cnt = 1; cnt <= M; cnt++){
        int q;
        scanf("%d", &q);
        if (q == 1){
            int i, v;
            scanf("%d %d", &i, &v);
            firstquery.push(make_pair(i, v));
        }
        else if (q == 2){
            int k, i, j;
            scanf("%d %d %d", &k, &i, &j);
            secondquery.push({{k, cnt}, {i, j}});
        }
    }

    int cnt = 0;
    while (!secondquery.empty()){
        int k = secondquery.top().first.first;
        int idx = secondquery.top().first.second;
        int s = secondquery.top().second.first;
        int e = secondquery.top().second.second;
        secondquery.pop();

        while (cnt < k && !firstquery.empty()){
            int x = firstquery.front().first;
            int y = firstquery.front().second;
            firstquery.pop();
            Q1(x, y);
            cnt++;
        }
        ll ans = Q2(s, e);
        res[idx] = ans;
    }

    for (int i = 0; i < MAXN; i++){
        if (res[i] != -1){
            printf("%lld\n", res[i]);
        }
    }

    return 0;
}