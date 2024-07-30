#include <iostream>
using namespace std;

int main(){
	int x;
	int y;
	int quadrant;
	
	cin >> x;
	cin >> y;
	
	if (x > 0)
		if (y > 0)
			quadrant = 1;
		else
			quadrant = 4;
		
	else
		if (y > 0)
			quadrant = 2;
		else
			quadrant = 3;
		
	cout << quadrant << endl;
	
	return 0;
}