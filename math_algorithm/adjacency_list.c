#include <stdio.h>
#include <stdlib.h>

int N, M, i, j, A[100009], B[100009];
int degree[100009], cnt[100009];
int *G[100009];

int main () {
    scanf("%d%d", &N, &M);
    for(i=1; i<=M; i++) scanf("%d%d", &A[i], &B[i]);

    //各頂点の次数を数える
    for (i=1; i<=N; i++) degree[i] = 0;
    for (i=1; i<=M; i++) {
        degree[A[i]] += 1;
        degree[B[i]] += 1;
    }

    //隣接リストGの構築
    for (i=1; i<=N; i++) {
        G[i] = (int*)malloc(degree[i]*sizeof(int));
        //int型配列G[i]のためのメモリ領域を動的に確保
    }

    //Gに辺の情報を追加していく
    for (i=1; i<=N; i++) cnt[i] = 0;  //変数cntは、頂点iに隣接する頂点のうち番号がi未満のものの個数を示す
    for (i=1; i<=M; i++) {
        G[A[i]][cnt[A[i]]] = B[i];
        cnt[A[i]] += 1;
        G[B[i]][cnt[B[i]]] = A[i];
        cnt[B[i]] += 1;
    }

    //答えを求める
    int Answer = 0;
    for (i=1; i<=N; i++) {
        int cnt = 0;
        for (j=0; j<degree[i]; j++) {
             //G[i][j]は頂点iに隣接している頂点のうち、j+1番目のもの
            if (G[i][j] < i) {
                cnt += 1;
            }
        }
        //自分自身より番号が小さい隣接頂点が1つであれば、Answerに1を加算する
        if (cnt == 1) Answer += 1;
    }

    printf("%d\n", Answer);

    //隣接リストGの削除
    for (i=1; i<=N; i++) {
        free(G[i]);
    }
    
    return 0;
}