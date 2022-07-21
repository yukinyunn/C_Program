#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979
#define DEG_RAD (PI/180.0)

int main (void) {
    int i ;
    double a, b;

    //while文版
    printf("******** while文 ********\n");
    i = 0;
    while (i<=90) {
        a = sin(i*DEG_RAD);  b = cos(i*DEG_RAD);
        printf("sin(%d)=%f, \t cos(%d)=%f \n", i, a, i, b);
        i += 30;
    }
    //for文版
    printf("******** for文 ********\n");
    for (i=0; i<=90; i+=30) {
        a = sin(i*DEG_RAD);  b = cos(i*DEG_RAD);
        printf("sin(%d)=%f, \t cos(%d)=%f \n", i, a, i, b);
    }
    //do-while文版
    printf("******** do-while文 ********\n");
    i = 0;
    do {
        a = sin(i*DEG_RAD);  b = cos(i*DEG_RAD);
        printf("sin(%d)=%f, \t cos(%d)=%f \n", i, a, i, b);
        i += 30;
    }while (i <= 90);

    return 0;
}