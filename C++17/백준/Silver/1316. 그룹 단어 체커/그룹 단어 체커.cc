#include <bits/stdc++.h>
using namespace std;

struct checker {
    bool flag;
    bool appeared;

    checker() : flag(false), appeared(false) {}
};

int main(void) {
    int N;
    scanf("%d", &N);

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        vector<checker> character(26);
        bool group = true;

        for (int j = 0; j < words[i].size(); j++) {
            int idx = words[i][j] - 'a';

            if (character[idx].appeared && !character[idx].flag) {
                group = false;
                break;
            }

            character[idx].appeared = true;
            character[idx].flag = true;

            if (j > 0 && words[i][j] != words[i][j - 1]) {
                character[words[i][j - 1] - 'a'].flag = false;
            }
        }

        if (group) cnt++;
    }

    printf("%d", cnt);
    return 0;
}
