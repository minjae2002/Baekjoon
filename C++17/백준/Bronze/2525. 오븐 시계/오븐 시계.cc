#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int total_minutes = A * 60 + B;
    
    total_minutes += C;
    
    int H = (total_minutes / 60) % 24;
    int M = total_minutes % 60;

    cout << H << " " << M << endl;

    return 0;
}