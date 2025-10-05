#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n, m;
    scanf("%d %d %d %d", &h, &w, &n, &m);

    int ans, row, col;

    if (h % (n + 1) == 0)
        row = h / (n + 1);
    else row = h / (n + 1) + 1;

    if (w % (m + 1) == 0)
        col = w / (m + 1);
    else col = w / (m + 1) + 1;

    ans = row * col;
    printf("%d\n", ans);
    return 0;
}