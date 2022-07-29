#include <stdio.h>
#include <stdlib.h>

#define N 5  //要素数の指定

double *double_vector(long i, long j);
void free_double_vector(double *a, long i);

int main(void) {
    double *a, *b;
    int i, j=0;

    printf("a の領域確保\n");  //配列aの添字は1 ~ N
    a = double_vector(1, N);
    for (i=1; i<=N; i++) {
        a[i] = (double)i/20.0;
        printf("a[%d]=%f \n", i, a[i]);
    }
    free_double_vector(a, 1);
    printf("a を解放しました\n");

    printf("b の領域確保\n");  //配列bの添字は2 ~ N+1
    b = double_vector(2, N+1);
    for (i=2; i<=N+1; i++) {
        b[i] = (double)i/20.0;
        printf("b[%d]=%f \n", i, b[i]);
    }
    free_double_vector(b, 2);
    printf("b を解放しました");

    return 0;
}

double *double_vector(long i, long j)  //a[i] ~ a[j]の領域の確保
{
    double *a;

    if((a=malloc( ((j-i+1)*sizeof(double))) ) == NULL) {
        printf("メモリが確保できません (from double_vector) \n");
        exit(1);
    }

    return(a-i);
}

void free_double_vector(double *a, long i)
{
    free((void *)(a + i));  //(void *)型のキャストが必要
}