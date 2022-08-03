#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
    int row;  //行の数
    int col;  //列の数
    double **m;  //行列
}matrix_t;

matrix_t *malloc_matrix(int nrow, int ncol);
void free_matrix(matrix_t *a, int nrow);

int main (void) {
    matrix_t *a;
    int i, j, nrow=2, ncol=3; 
    a = malloc_matrix(nrow, ncol);  //行列の領域を確保

    for (i=1; i<=nrow; i++) {
        for (j=1; j<=ncol; j++) {
            *(*(a->m+i)+j) = (i+j)/2.0;
            printf("a[%d][%d]=%f \n", i, j, *(*(a->m+i)+j));  //添字は1から
        }
    }

    free_matrix(a, nrow);  //領域の解放
    return 0;
}

matrix_t *malloc_matrix(int nrow, int ncol)
//a[1][1] ... a[nrow][ncol]の行列を作成
{
    matrix_t *a;
    int i;
    
    if ((a=(matrix_t *)malloc(sizeof(matrix_t))) == NULL)
    {
        printf("行列用の領域が確保できません(malloc_matrix 内)\n");
        exit(1);
    }
    a->row = nrow;
    a->col = ncol;

    a->m = malloc(nrow*sizeof(double *));  //行の確保
    a->m = a-> m-1;  //行を1つずらす
    for (i=1; i<=nrow; i++) *(a->m+i) = malloc(ncol*sizeof(double));  //列の確保
    for (i=1; i<=nrow; i++) *(a->m+i) = *(a->m+i)-1;  //列を1つずらす

    return a;
}

void free_matrix(matrix_t *a, int nrow)
//malloc_matrixで確保した領域を解放
{
    int i; 
    for (i=1; i<=nrow; i++) free((void *)(*(a->m+i)+1));
    free((void *)(a->m+1));
}
