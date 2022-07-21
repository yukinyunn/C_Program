#include <stdio.h>
long long N, M;
long long A[200009], B[200009], S[200009]; 

int main () {
    scanf("%lld", &N);
    for (int i=1; i<=N-1; i++) scanf("%lld", &A[i]);
    scanf("%lld", &M);
    for (int i=1; i<=M; i++) scanf("%lld", &B[i]);
 
    S[1] = 0;
    for (int i=2; i<=N; i++) S[i] = S[i-1] + A[i-1];

    long long Ans = 0;
    for (int i=1; i<=M-1; i++) {
        if (B[i] < B[i+1]) {
            Ans += (S[B[i+1]] - S[B[i]]);
        }
        else {
            Ans += (S[B[i]] - S[B[i+1]]);
        }
    }

    printf("%lld\n", Ans);
    return 0;
}
