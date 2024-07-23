#include <iostream>
using namespace std;

int main(){
	int year;
	int yun = 0;
	cin >> year;
	
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0)
				yun = 1;
			else 
				yun = 0;
		else 
			yun = 1;
		
	cout << yun << endl;
	
	return 0;	
}