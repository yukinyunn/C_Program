#include <stdio.h>
#include <math.h>

int matrix_input(double *a, double *b, double *c, double *d);
int eigen(double a, double b, double c, double d, double *x1, double *x2);

int main (void) {
    double a, b, c, d, x1, x2;  //x1, x2には固有値が入る

    matrix_input(&a, &b, &c, &d);
    eigen(a, b, c, d, &x1, &x2);
    printf("main関数における x1 および x2 の値は x1=%f, x2=%f です\n", x1, x2);

    return 0;
}

int matrix_input(double *a, double *b, double *c, double *d) {
    printf("2 × 2 行列Aの要素\n a \t b \n c \t d \n \
            \r を順に半角スペースで区切って入力してください\n");
    scanf("%lf %lf %lf %lf", a, b, c, d);
    printf("あなたの入力した行列は\n %f %f \n %f %f\n です\n", *a, *b, *c, *d);

    return 0;
}

int eigen(double a, double b, double c, double d, double *x1, double *x2) {
    double B, C, D;

    B = a + d; C = a * d - b * c;  //B=a+d, C=ad-bc
    D = B * B - 4.0 * C;  //判別式の計算 D=B^2-4C

    if (D >= 0) {
        *x1 = (B + sqrt(D)) / 2.0;
        *x2 = (B - sqrt(D)) / 2.0;
        if (D == 0) {
            printf("行列Aの固有値は2重根で%f です\n", *x1);
        }
        else {
            printf("行列Aの固有値は%f と%f です\n", *x1, *x2);
        }
    }
    else {
        *x1 = B / 2.0;        //実部の計算
        *x2 = sqrt(-D) / 2.0;  //虚部の計算
        printf("行列Aの固有値は%f +%f i と%f -%f i です\n", *x1, *x2, *x1, *x2);
    }
    return 0;
}