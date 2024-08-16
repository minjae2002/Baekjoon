#include <bits/stdc++.h>
using namespace std;
#define MAX 400

int R, C;
char chart[MAX][MAX];

void input(){
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf(" %c", &chart[i][j]);
        }
    }
}

int find_max_perimeter() {
    int max_perimeter = 0;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (chart[r][c] == '.') {
                int min_width = C;
                for (int i = r; i < R && chart[i][c] == '.'; i++) {
                    int width = 0;
                    while (c + width < C && chart[i][c + width] == '.') {
                        width++;
                    }
                    min_width = min(min_width, width);
                    if (min_width == 0) break;
                    int perimeter = 2 * (min_width + (i - r + 1)) - 1;
                    max_perimeter = max(max_perimeter, perimeter);
                }
            }
        }
    }
    
    return max_perimeter;
}

int main(void) {
    input();
    int result = find_max_perimeter();
    printf("%d\n", result);
    return 0;
}