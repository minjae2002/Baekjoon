#include <iostream>
using namespace std;

long long Fib(int n){
	long long D[n];
	D[0] = 0;
	D[1] = 1;
	for (int i = 2; i <= n; i++){
		D[i] = D[i - 1] + D[i - 2];
	}
	return D[n];
}

int main(){
	int n;
	cin >> n;
	cout << Fib(n);
}
