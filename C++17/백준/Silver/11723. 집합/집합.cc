#include <cstdio>

bool S[21];  // 1부터 20까지의 값을 표현하기 위해 21로 설정

int main() {
    int M;
    scanf("%d", &M);

    char command[10];
    int x;

    while (M--) {
        scanf("%s", command);
        if (command[0] == 'a' && command[1] == 'd') { // "add"
            scanf("%d", &x);
            S[x] = true;
        } else if (command[0] == 'r') { // "remove"
            scanf("%d", &x);
            S[x] = false;
        } else if (command[0] == 'c') { // "check"
            scanf("%d", &x);
            printf("%d\n", S[x] ? 1 : 0);
        } else if (command[0] == 't') { // "toggle"
            scanf("%d", &x);
            S[x] = !S[x];
        } else if (command[0] == 'a' && command[1] == 'l') { // "all"
            for (int i = 1; i <= 20; ++i) {
                S[i] = true;
            }
        } else if (command[0] == 'e') { // "empty"
            for (int i = 1; i <= 20; ++i) {
                S[i] = false;
            }
        }
    }

    return 0;
}
