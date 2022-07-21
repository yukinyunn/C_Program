#include <stdio.h>

int main () {
    long long a, b, n, x;

    scanf("%lld\n", &n);
    scanf("%lld",  &a);
 
    for(long long i=2; i<=n; i++) {
        scanf("%lld", &b);
        if (a < b) {
            x = b;
            b = a;
            a = x;
        }
        x = a;
        while(a % b != 0) {
            a += x;
        }
    }
    printf("%lld", a);

    return 0;
}