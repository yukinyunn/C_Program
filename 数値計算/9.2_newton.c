#include <stdio.h>
#include <math.h>

#define EPS pow(10.0 ,-8)
#define KMAX 10

double f(double x);
double df(double x);

int main (void) {
    int k = 0;
    double x, d;
    scanf("%lf", &x);  //初期値の入力

    do {
        d = -f(x)/df(x);
        x = x + d;
        k++;
    }while (fabs(d) > EPS && k < KMAX);

    if (k == KMAX) {
        printf("答えが見つかりませんでした\n");
    }
    else {
        printf ("答えは x=%f です\n", x);
    }

    return 0;
}

double f(double x) {
    return (x - exp(1/x));
}
double df(double x) {
    return (1 + (1/(x * x)) * exp(1/x));
}