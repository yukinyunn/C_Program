#include <stdio.h>
#include <stdlib.h>

int R, C, sx, sy, gx, gy, start, goal;
char c[59][59];

int edges, A[5009], B[5009], degree[2509], cnt[2509];
int *G[2509];
int dist[2509];

int main () {
    scanf("%d%d", &R, &C);
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &gx, &gy);
    int i, j;
    for (i=1; i<=R; i++) {
            scanf("%s", c[i]+1); 
            //入力した文字列をc[i][1], c[i][2], ... に格納
    }
    start = (sx - 1) * C + sy;
    goal = (gx - 1) * C + gy;

    //グラフの辺をリストアップ(edgesは現在の辺の数)
    edges = 0;
    for (i=1; i<=R; i++) {
        for (j=1; j<=C; j++) {
            if (c[i][j] == '.' && c[i][j+1] == '.') {
                edges += 1;
                A[edges] = (i-1) * C + j; //マス(i, j)の頂点番号
                B[edges] = (i-1) * C + (j+1); //マス(i, j+1)の頂点番号
            }
        }
    }
    for (i=1; i<=R-1; i++) {
        for (j=1; j<=C; j++) {
            if (c[i][j] == '.' && c[i+1][j] == '.') {
                edges += 1;
                A[edges] = (i-1) * C + j; //マス(i, j)の頂点番号
                B[edges] = i * C + j; //マス(i+1, j)の頂点番号
            }
        }
    }

    //隣接リストGの作成
    for (i=1; i<=R*C; i++) degree[i] = 0;
	for (i=1; i<=edges; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i=1; i<=R*C; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i=1; i<=R*C; i++) cnt[i] = 0;
	for (i=1; i<=edges; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}

    //キューQの定義
    int Q[2509];
    int QL = 0, QR = 0;
    for (i=1;  i<=R*C; i++) {
        dist[i] = -1; //dist[i] = -1 のとき、未到達の白色頂点である
    }
    dist[start] = 0;
    Q[QR] = start; QR++; //Qにstartを追加

    //幅優先探索
    while (QL != QR) {
        int pos = Q[QL]; //Qの先頭を調べる
        QL++; //Qの先頭を取り出す
        for (i=0; i<degree[pos]; i++) {
            int nex = G[pos][i];
            if (dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                Q[QR] = nex; QR++; //Qにnexを追加
            }
        }
    }

    //隣接リストGの削除
    for (i=1; i<=R*C; i++) {
        free(G[i]);
    }

    printf("%d\n", dist[goal]);

    return 0;
}