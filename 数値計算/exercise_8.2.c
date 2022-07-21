#include <stdio.h>
#include <stdlib.h>

#define A_ROW 3
#define A_COLUMN 4

#define B_ROW 4
#define B_COLUMN 5

void matrix_product(double a[][A_COLUMN], double b[][B_COLUMN]);

int main (void) {
    FILE *fp;
    double a[A_ROW][A_COLUMN], b[B_ROW][B_COLUMN];
    int i, j;

    if ((fp = fopen("input_matrix.dat", "r")) == NULL) {
        printf("ファイルが見つかりません : input_matrix.dat \n");
        exit(1);
    }

    printf("行列Aは次の通りです\n");
    for (i=0; i<A_ROW; i++) {
        for (j=0; j<A_COLUMN; j++) {
            fscanf(fp, "%lf", &a[i][j]);
            printf("%5.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("行列Bは次の通りです\n");
    for (i=0; i<B_ROW; i++) {
        for (j=0; j<B_COLUMN; j++) {
            fscanf(fp, "%lf", &b[i][j]);
            printf("%5.2f\t", b[i][j]);
        }
        printf("\n");
    }
    
    matrix_product(a, b);
    fclose(fp);
    return 0;
}

void matrix_product(double a[][A_COLUMN], double b[][B_COLUMN]) {
    double c[A_ROW][B_COLUMN];
    int i, j, k;

    printf("A × B の結果は次の通りです. \n");
    for (i=0; i<A_ROW; i++) {
        for (j=0; j<B_COLUMN; j++) {
            c[i][j] = 0.0;
            for (k=0; k<B_ROW; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%8.3f\t", c[i][j]);
        }
        printf("\n");
    }
} 
