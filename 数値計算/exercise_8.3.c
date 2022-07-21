#include <stdio.h>
#include <stdlib.h>

#define N 4

void matrix_product(double a[][N], double b[][N], FILE *fout);
void input_matrix(double (*a)[N], char c, FILE *fin, FILE *fout);

int main (void) {
    FILE *fin, *fout;
    double a[N][N], b[N][N];

    if ((fin = fopen("matrix_in.dat", "r")) == NULL) {
        printf("ファイルが見つかりません : matrix_in.dat \n");
        exit(1);
    }
    if ((fout = fopen("matrix_in.dat", "w")) == NULL) {
        printf("ファイルが作成できません : matrix_in.dat \n");
        exit(1);
    }

    printf("行列 A と B の積を求めます. \n");
    fprintf(fout, "行列 A と B の積を求めます. \n");
    
    input_matrix(a, 'A', fin, fout);
    input_matrix(b, 'B', fin, fout);
    matrix_product(a, b, fout);

    fclose(fin);
    fclose(fout);

    return 0;
}

void matrix_product(double a[][N], double b[][N], FILE *fout) {
    double c[N][N];
    int i, j, k;
    
    printf("A × B の結果は次の通りです. \n");
    fprintf(fout, "A × B の結果は次の通りです. \n");
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            c[i][j] = 0.0;
            for (k=0; k<N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%8.3f\t", c[i][j]);
            fprintf(fout, "%8.3f\t", c[i][j]);
        }
    }
    printf("\n");
    fprintf(fout, "\n");
}

void input_matrix(double (*a)[N], char c, FILE *fin, FILE *fout) {
    int i, j;

    printf("行列%c は次の通りです\n", c);
    fprintf(fout, "行列%c は次の通りです\n", c);
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            fscanf(fin, "%lf", &a[i][j]);
            printf("%5.2f\t", a[i][j]);
            fprintf(fout, "%5.2f\t", a[i][j]);
        }
        printf("\n");
        fprintf(fout, "\n");
    }
}
