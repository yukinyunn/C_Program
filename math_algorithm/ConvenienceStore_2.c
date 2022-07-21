#include <stdio.h>

int T, N;
int L[500009], R[500009], B[500009], A[500009];

int main () {
    scanf("%d", &T);
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    for (int i=0; i<=T; i++) B[i] = 0;
    for (int i=1; i<=N; i++) {
        B[L[i]] += 1; //出勤
        B[R[i]] -= 1; //退勤
    }

    A[0] = B[0];
    for (int i=1; i<=T; i++) {
        A[i] = A[i-1] + B[i];
    }

    for (int i=0; i<T; i++) printf("%d\n", A[i]);
    return 0;
}