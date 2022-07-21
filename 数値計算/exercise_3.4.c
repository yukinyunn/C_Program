#include <stdio.h>
#include <math.h>

int main (void) {
    double a, b, c, d, B, C, D, x1, x2;

    printf("2×2行列Aの要素\n a \t b \n c \t d \n を順に半角スペースで区切って入力してください\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("あなたの入力した行列は\n %f %f \n %f %f \n です\n", a, b, c, d);

    B = a + d; C = a * d - b * c;
    D = B * B - 4 * C;

    if (D >= 0) {
        x1 = (B + sqrt(D))/2.0;
        x2 = (B - sqrt(D))/2.0;
        if (D == 0) {
            printf("行列Aの固有値は2重根で%f です\n", x1);
        }
        else {
            printf("行列Aの固有値は%f と%f です\n", x1, x2);
        }
    }
    else {
        x1 = B/2.0;         //実部の計算
        x2 = sqrt(-D)/2.0;  //虚部の計算
        printf("行列Aの固有値は%f+%f i と%f-%f i です\n", x1, x2, x1, x2);
    }
    return 0;
}