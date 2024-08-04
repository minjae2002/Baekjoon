#include <bits/stdc++.h>
using namespace std;

int main(void){
	// 생성자가 있는 수는 모두 1001A + 101B + 11C + 2D (A, B, C, D는 0 이상) 꼴로 표현된다. 
	int num[10000];
	for (int i = 0; i < 10000; i++){
		num[i] = i + 1;
	} 
	for (int A = 0; A < 10; A++){
		for (int B = 0; B < 10; B++){
			for (int C = 0; C < 10; C++){
				for (int D = 0; D < 10; D++){
					int number = 1001 * A + 101 * B + 11 * C + 2 * D;
					if (number <= 10000) num[number - 1] = 0;
				}
			}
		}
	}
	
	for (int i = 0; i < 10000; i++){
		if (num[i] != 0) printf("%d\n", num[i]);
	}
	
	return 0;
}