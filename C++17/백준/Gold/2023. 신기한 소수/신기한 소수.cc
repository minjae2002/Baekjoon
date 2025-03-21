#include <bits/stdc++.h>
using namespace std;

int N;

bool isPrime(int num){
    for (int i = 2; i <= num / 2; i++){
        if (num % i == 0) return false;
    }
    return true;
}

void Solve(int num, int idx){
    if (idx == N){
        if (isPrime(num)) printf("%d\n", num);
        return;
    }
    for (int i = 1; i < 10; i++){
        if (i % 2 == 0) continue;
        if (isPrime(num * 10 + i)) Solve(num * 10 + i, idx + 1);
    }
}

int main(){
    scanf("%d", &N);
    Solve(2, 1);
    Solve(3, 1);
    Solve(5, 1);
    Solve(7, 1);

    return 0;
}