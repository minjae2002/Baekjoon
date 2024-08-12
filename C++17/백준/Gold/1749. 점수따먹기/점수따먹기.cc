#include <bits/stdc++.h>
using namespace std;
#define MAX 201
#define INF 987654321

int matrix[MAX][MAX] = {0,};
int sum_matrix[MAX][MAX] = {0,};
int N, M;

void input(){
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void sum(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            sum_matrix[i][j] = matrix[i][j] + sum_matrix[i - 1][j] + sum_matrix[i][j - 1] - sum_matrix[i - 1][j - 1];
        }
    }
}

int main(){
    input();
    sum();
    int res = -INF;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            for (int a = i; a <= N; a++){
                for (int b = j; b <= M; b++){
                    int submatrix_sum = sum_matrix[a][b] - (i > 1 ? sum_matrix[i - 1][b] : 0)
                                        - (j > 1 ? sum_matrix[a][j - 1] : 0) + (i > 1 && j > 1 ? sum_matrix[i - 1][j - 1] : 0);
                    res = max(res, submatrix_sum);
                }
            }
        }
    }

    printf("%d", res);
    return 0;
}
