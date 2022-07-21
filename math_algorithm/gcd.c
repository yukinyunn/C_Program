#include <stdio.h>

int main () {
    long int n, a, b, x;

    scanf("%ld\n", &n);
    scanf("%ld", &a);

    for (long int i=2; i<=n; i++) {
        scanf("%ld", &b);
        while (b != 0) {
            x = b;
            b = a % b;
            a = x;
        }
        if (a == 1) {
            break;
        }
    }
    printf("%ld\n", a);

    return 0;
}