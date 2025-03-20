#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int N;
    scanf("%d", &N);
    vector<pii> A(N);

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i].first);
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int Max = 0;

    for (int i = 0; i < N; i++){
        if (Max < A[i].second - i){
            Max = A[i].second - i;
        }
    }

    printf("%d", Max + 1);

    return 0;
}