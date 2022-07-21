#include <stdio.h>

void init_val(double a[], int n);

int main () {

    double x[6];
    int i, n;

    n = sizeof(x) / sizeof(x[0]);  //配列の要素数を求める
    init_val(x, n);  //配列の初期化
    printf("配列の要素数は %d です. ", n);
    printf("各配列要素の中身は次の通りです. \n");
    for (i=0; i<n; i++) {
        printf("x[%d]=%f \t アドレスは %p です\n", i, x[i], &x[i]);
    }

    return 0;
}

void init_val(double a[], int n) {
    int i;

    for (i=0; i<n; i++) {
        *(a+i) = i*0.123;
    }
}
