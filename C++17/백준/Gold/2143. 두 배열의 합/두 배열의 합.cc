#include <bits/stdc++.h>
using namespace std;

const int INF = 2e8;
typedef long long ll;
int t, n, m;
int a[1001], b[1001];
vector<int> v, w;

int main(){
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++){
        int sum = a[i];
        v.push_back(sum);
        for (int j = i + 1; j < n; j++){
            sum += a[j];
            v.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++){
        int sum = b[i];
        w.push_back(sum);
        for (int j = i + 1; j < m; j++){
            sum += b[j];
            w.push_back(sum);
        }
    }

    sort(w.begin(), w.end());

    ll ans = 0;
    for (auto item : v){
        int diff = t - item;
        auto ub = upper_bound(w.begin(), w.end(), diff);
        auto lb = lower_bound(w.begin(), w.end(), diff);
        ans += (ub - lb);
    }

    printf("%lld", ans);

    return 0;
}