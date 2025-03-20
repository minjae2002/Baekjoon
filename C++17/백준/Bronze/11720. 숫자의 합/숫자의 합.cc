#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string num;
    cin >> N;
    cin >> num;

    int sum = 0;
    for (int i = 0; i < num.length(); i++){
        sum += num[i] - '0';
    }

    cout << sum << endl;
    return 0;
}