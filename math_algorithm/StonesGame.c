#include <stdio.h>
#include <stdbool.h>

int main (void) {
    long long N;
    scanf("%lld", &N);

    bool flag = false;
    for (int i=1; i<=60; i++) {
        if (N == (1LL << i) - 1LL) flag = true;
    }

    if (flag == true) printf("Seocnd");
    else printf("First");

    return 0;
}