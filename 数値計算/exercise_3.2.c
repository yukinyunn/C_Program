#include <stdio.h>
#include <math.h>

int main () {
    double a, b, c, D, x1, x2;

    printf("ax^2+bx+c=0の係数a, b, cを入力してください---> ");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            printf("係数がおかしい\n");
        }
        else {
            x1 = -c/b;
            printf("解は, %fです\n", x1);
        }
    }
    else {
        D = b*b - 4*a*c;
        if (D >= 0) {
            x1 = (-b+sqrt(D))/(2.0*a);
            x2 = (-b-sqrt(D))/(2.0*a);
            if (D == 0) {
                printf("解は重解となり、%fです\n", x1);
            }
            else {
                printf("解は, %f と %f です\n", x1, x2);
            }
        }
        else {
            printf("虚数解となるため、実数解はありません\n");
        }
    }
    return 0;
}