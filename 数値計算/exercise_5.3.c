#include <stdio.h>

#define L 4
#define M 5
#define N 1

int main () {
    int i, j, k;
    double a[L][M], b[M][N], c[L][N];

    printf("%d x %d 行列Aの各要素を入力します\n", L, M);
    for (i=0; i<L; i++) {
        for (j=0; j<M; j++) {
            printf("A[%d][%d] の値は? ---> ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
    }
    printf("%d x %d 行列Bの各要素を入力します\n", M, N);
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf("A[%d][%d] の値は? ---> ", i+1, j+1);
            scanf("%lf", &b[i][j]);
        }
    }
    printf("行列Aと行列Bの値は次の通りです. \n");
    printf("行列A = \n");
    for (i=0; i<L; i++) {
        for (j=0; j<M; j++) {
            printf("%8.3f", a[i][j]);
        }
        printf("\n");
    }
    printf("行列B = \n");
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            printf("%8.3f", b[i][j]);
        }
        printf("\n");
    }

    printf("A × B の結果は次の通りです. \n");
    for (i=0; i<L; i++) {
        for (j=0; j<N; j++) {
            c[i][j] = 0.0;
            for (k=0; k<M; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%8.3f", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}