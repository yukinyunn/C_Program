#include <stdio.h>

int K, N, Q;
int A[209];
int L[209];

int main () {
    //入力
    scanf("%d%d%d", &N, &K, &Q);
    for (int i=1; i<=K; i++) scanf("%d", &A[i]);
    for (int i=1; i<=Q; i++) scanf("%d", &L[i]);
    
    //マスの移動
    for (int i=1; i<=Q; i++) {
        if ((L[i] == K && A[L[i]] < N) || (L[i] < K && A[L[i]] + 1 < A[L[i] + 1])) {
            A[L[i]]++;
        }
    }
    //出力
    for (int i=1; i<=K; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}