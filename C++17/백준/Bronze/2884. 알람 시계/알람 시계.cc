#include <iostream>
using namespace std;

int main(){
	int H, M;
	cin >> H >> M;
	
	int dM = M - 45;
	
	if (dM < 0){
		M = dM + 60;
		if (H > 0)
			H = H - 1;
		else 
			H = 23;
	}
	else {
		M = M - 45;
	}
	
	cout << H << " " << M << endl;
	
	return 0;
}