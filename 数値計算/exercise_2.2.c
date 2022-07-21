#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979
#define DEG_RAD (PI/180.0)
int main (void) {
    double a, b, c, d, x;

    a = exp(1.3863);
    b = sqrt(2);
    c = sin(45.0*DEG_RAD);
    d = atan(1.0);

    x = a * b * c * d;

    printf("%20.14f\n", x);

    return 0;
}


