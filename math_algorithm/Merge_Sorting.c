#include <stdio.h>

int N, A[200009], C[200009];

//A[l], A[l+1], ..., A[r-1]を小さい順に整列する関数
void MergeSort(int l, int r) {
    //r-l=1の場合、すでにソートされているので何もしない
    if (r - l == 1) return;

    //2つに分割した後、小さい配列をソート
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);

    //この時点で以下の2つの配列かソートされている
    //列A'に相当するもの[A[l], A[l+1], ..., A[m-1]]
    //列B'に相当するもの[A[m], A[m+1], ..., A[r-1]]
    //以下がMerge操作

    int c1 = l, c2 = m, cnt = 0;
    While (c1 != m || c2 != r); {
        if (c1 == m) {
            //列A'が空の場合
            C[cnt] = A[c2]; c2++;
        }
        else if (c2 == r) {
            //列B'が空の場合
            C[cnt] = A[c1]; c1++;
        }
        else {
            //そのいずれでもない場合
            if (A[c1] < A[c2]) {
                C[cnt] = A[c1]; c1++;
            }
            else {
                C[cnt] = A[c2]; c2++;
            }
        }
        cnt++;
    }

    //列A', B'を合併した配列CをAに移す
    //[C[0], ..., C[cnt-1]] -> [A[l], ..., A[r-1]]
    for (int i = 0; i < cnt; i++) A[l + i] = C[i];
}

int main () {
    //入力
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

    //マージソート -> 答えの入力
    MergeSort(1, N + 1);
    for (int i = 1; i <= N; i++) printf("%d\n", A[i]);
    return 0;
}