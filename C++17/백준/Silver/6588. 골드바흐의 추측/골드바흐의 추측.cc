#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

vector<bool> is_prime(MAXN, true);

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
}

int main(void){
    sieve();
	int n;
	while (true){
		scanf("%d", &n);
		if (n == 0) break;
		
        bool found = false;
		for (int i = 3; i <= n / 2; i++){
			if (is_prime[i] && is_prime[n - i]){
                printf("%d = %d + %d\n", n, i, n - i);
                found = true;
                break;
            }
		}
        if (!found) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0; 
}