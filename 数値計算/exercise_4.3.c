#include <stdio.h>
#include <math.h>

#define EPS pow(10.0, -8.0)

int main () {
    double s = 0.0, k, x1 = 3.0, x2;
    int cnt = 0;

    for (int k=1.0; k<=100000.0; k++) {
        s += 1.0/pow(k, 2.0);
    }
    s *= 6.0;
    
    while (fabs(x1-x2) > EPS) {
        x2 = x1;
        x1 = (x1 + s/x1) / 2.0;
        cnt += 1;
        printf("|x1-x2|=%f です \n", fabs(x1-x2));
    }
    printf("反復回数は %d です \n", cnt);
    printf("結果は %15.10f です\n", x1);
    return 0;
}