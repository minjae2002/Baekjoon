#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    sort(A.begin(), A.end());
    int Result = 0;

    for (int k = 0; k < N; k++){
        long find = A[k];
        int i = 0;
        int j = N - 1;

        while (i < j){
            if (A[i] + A[j] == find){
                if (i != k && j != k){
                    Result++;
                    break;
                }
                else if (i == k) i++;
                else if (j == k) j--;
            }
            else if (A[i] + A[j] < find) i++;
            else j--;
        }
    }

    printf("%d", Result);
    return 0;
}