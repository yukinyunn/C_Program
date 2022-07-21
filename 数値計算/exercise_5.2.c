#include <stdio.h>

#define N 5

int main (void) {
    double a[N] = {3.24, 9.26, -2.25, 1.23, 9.125};
    int i, flag;
    double tmp;

    do {
        flag = 0;
        for (i=0; i<N-1; i++) {
            if (a[i] > a[i+1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                flag = 1;     //値の交換があればフラグを立てる
            }
        }
    }while (flag == 1);

    for (i=0; i<N; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");

    return 0;
}