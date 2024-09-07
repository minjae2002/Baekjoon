#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

void input(){
    scanf("%d", &N);
    arr.resize(N);

    for (int i = 0 ; i < N; i++){
        scanf("%d", &arr[i]);
    }
}

int LIS(){
    vector<int> lis;

    for (int i = 0; i < N; i++){
        int tmp = arr[i];
        auto idx = lower_bound(lis.begin(), lis.end(), tmp);
        
        if (idx == lis.end()) lis.push_back(tmp);
        else *idx = tmp;
    }

    return lis.size();
}

int main(){
    input();
    int ans = LIS();
    printf("%d\n", ans);

    return 0;
}