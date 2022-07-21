#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
    double a, b, c, d, x, y;

    a = 4*atan(1.0/5.0); 
    b = atan(1.0/239.0);
    c = 1.0/(7.0*6.0*5.0*4.0*3.0*2.0) + 1.0/(6.0*5.0*4.0*3.0*2.0)
      + 1.0/(5.0*4.0*3.0*2.0) + 1.0/(4.0*3.0*2.0) + 1.0/(3.0*2.0)
      + 1.0/2.0 + 1.0 +1.0;
    
    x = 4 * (a - b);
    y = fabs(c-exp(1.0));
    
    printf("%15.13f\n%15.13f\n%15.13f\n", x, c, y);

    return 0;
}

