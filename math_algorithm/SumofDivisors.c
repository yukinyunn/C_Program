#include <stdio.h>

long long N;
long long F[10000009];
long long Ans = 0;

int main () {
    // 入力 -> 配列の初期化
    scanf("%lld", &N);
    for (int i=1; i<=N; i++) F[i] = 0;

    // F[1], F[2], ..., F[N]を計算する
    for (int i=1; i<=N; i++) {
        // F[i], F[2i], ... に1を加算する
        for (int j=i; j<=N; j+=i) F[j] += 1;
    }
    
    // 答えを求める -> 出力
    for (int i=1; i<=N; i++) {
        Ans += 1LL * i * F[i];
    }

    printf("%lld\n", Ans);
    return 0;

}