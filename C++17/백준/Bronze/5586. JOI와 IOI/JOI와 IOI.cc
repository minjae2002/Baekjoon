#include <bits/stdc++.h>
using namespace std;

int Solve(string text, string pattern) {
    int N = text.size();
    int M = pattern.size();
    int i, j, ans = 0;
    for (i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == M) ans++;
    }
    return ans;
}

int main() {
    string text;
    cin >> text;
    int ans1 = Solve(text, "JOI");
    int ans2 = Solve(text, "IOI");
    cout << ans1 << endl << ans2 << endl;

    return 0;
}
