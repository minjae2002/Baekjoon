#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	
	for (int i = 1; i <= 9; i++){
		cout << N << " * " << i << " = " << i * N << '\n';
	}
	
	return 0;
}