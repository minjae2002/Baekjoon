#include <iostream>
using namespace std;

int main(){
	int A, B, C;
	cin >> A >> B;
	cin >> C;
	
	int C_H = C / 60;
	int C_M = C % 60;
	
	if (B + C_M >= 60){
		B = B + C_M - 60;
		A = (A + C_H + 1) % 24;
	}
	else {
		B = B + C_M;
		if (A + C_H >= 24)
			A = A + C_H - 24;
		else
			A = A + C_H;
	}
	cout << A << " " << B << endl;
	
	return 0;
}