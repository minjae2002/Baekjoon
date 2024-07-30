#include <iostream>
using namespace std;

int main(){
	int n1, n2, n3, n4, n5, n6;
	
	cin >> n1;
	cin >> n2;
	
	int n2_1 = n2 % 10;
	int n2_10 = (n2 / 10) % 10;
	int n2_100 = (n2 / 100);

	n3 = n1 * n2_1;
	n4 = n1 * n2_10;
	n5 = n1 * n2_100;
	
	n6 = n3 + (10 * n4) + (100 * n5);

	cout << n3 << endl << n4 << endl << n5 << endl << n6 << endl;
	
	return 0;
}