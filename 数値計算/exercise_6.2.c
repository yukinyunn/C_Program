#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solve(double a, double  b, double c, double *D, double *x1, double *x2);

int main (void) {
    double a, b, c, D, x1, x2;
    printf(" ax^2+bx+c=0 の係数 a, b, c を入力してください---> ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("2次方程式を解いた結果は次の通りです. \n");
    solve(a, b, c, &D, &x1, &x2);

    printf("この時の判別式の値は%f です. \n", D);
    printf("この時の x1 と x2 の和は%f です. \n", x1+x2);
    return 0;
}

int solve(double a, double  b, double c, double *D, double *x1, double *x2) {
    if (a == 0){
        if (b == 0) {
            printf("係数がおかしい \n");
            exit(0);
        }
        else {
            *x1 = -c/b;
            printf("解は %f です\n", *x1);
            exit(0);
        }
    }
    else {
        *D = b * b - 4 * a * c;
        if (*D >= 0) {
            *x1 = (-b + sqrt(*D)) / (2.0 * a);
            *x2 = (-b - sqrt(*D)) / (2.0 * a);
            if (*D == 0) {
                printf("解は重解となり, %f です\n", *x1);
                *x2 = *x1;
            }
            else {
                printf("解は %f と %f です\n", *x1, *x2);
            }
        }
        else {
            printf("虚数解となるため, 実数解はありません\n");
            *x1 = sqrt(-1.0);
            *x2 = sqrt(-1.0);
        }
    }
    return 0;
}