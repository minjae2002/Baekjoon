#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MINX(x, y) (((x) < (y)) ? (x) : (y))

int N, M;
int MAP[MAX][MAX];

void input(){
	cin >> N >> M;
  	for (int i = 1; i <= N; i++){
    	string input;
		cin >> input;
    	for (int j = 0; j < input.length(); j++){
			MAP[i][j + 1] = input[j] - '0';
    	}
  	}
}

void Solution(){
	int maxlen = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (MAP[i][j] != 0){
				MAP[i][j] = MINX(MAP[i - 1][j - 1], MINX(MAP[i][j - 1], MAP[i - 1][j])) + 1;
				if(maxlen < MAP[i][j]) maxlen = MAP[i][j];
			}
		}
	}	
	cout << maxlen * maxlen << endl;
}

int main(){
	ios_base:: sync_with_stdio (false); cin. tie (NULL); cout. tie (NULL);
	input();
	Solution();
	return 0;
}