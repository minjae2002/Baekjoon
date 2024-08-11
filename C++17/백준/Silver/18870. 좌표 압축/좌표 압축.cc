#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> coord;
vector<ll> cpy;

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        int val;
        scanf("%d", &val);
        coord.push_back(val);
        cpy.push_back(val);
    }

    sort(cpy.begin(), cpy.end());
    cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());

    for (int i = 0; i < N; i++){
        auto val = lower_bound(cpy.begin(), cpy.end(), coord[i]) - cpy.begin();
        coord[i] = val;
    }
    for (int i = 0; i < N; i++){
        printf("%d ", coord[i]);
    }
    return 0;
}