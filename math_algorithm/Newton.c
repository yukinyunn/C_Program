#include <stdio.h>

int main () {
    double r = 2.0;
    double a = 2.0;

    for (int i=1; i<=5; i++) {
        //点（a, f(a)）のx座標とy座標を求める
        double zahyou_x = a;
        double zahyou_y = a * a * a;

        //接線の式を求める[y = (sessen_a)x + sessen_b とする]
        double sessen_a = 3 * zahyou_x * zahyou_x;
        double sessen_b = zahyou_y - sessen_a * zahyou_x;

        //次のaの値を求める
        double next_a = (r - sessen_b) / sessen_a;
        printf("Step #%d : a = %.12lf -> %.12lf\n", i, a, next_a);
        a = next_a;
    }
    return 0; 
}