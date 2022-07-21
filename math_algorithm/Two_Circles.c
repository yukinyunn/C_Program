#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double X1, Y1, R1;
double X2, Y2, R2;

int main () {
    scanf("%lf%lf%lf", &X1, &Y1, &R1);
    scanf("%lf%lf%lf", &X2, &Y2, &R2);

    double d = sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2)); 

    if (d < fabs(R1-R2)) printf("1\n"); //内部にある
    else if (d == fabs(R1-R2)) printf("2\n"); //内接する
    else if (d < R1+R2) printf("3\n"); //2点で交わる
    else if (d == R1+R2) printf("4\n"); //外接する
    else printf("5\n"); //外部にある

    return 0;
}
