#include <stdio.h>

int main (void) {
    double a[4][4];
    double b[1][4];

    double a[0][0] = 1.0;
    double a[0][1] = 2.0;
    double a[0][2] = 1.0;
    double a[0][3] = 1.0;

    double a[1][0] = 4.0;
    double a[1][1] = 5.0;
    double a[1][2] = -2.0;
    double a[1][3] = 4.0;

    double a[2][0] = 4.0;
    double a[2][1] = 3.0;
    double a[2][2] = -3.0;
    double a[2][3] = 1.0;

    double a[3][0] = 2.0;
    double a[3][1] = 1.0;
    double a[3][2] = 1.0;
    double a[3][3] = 3.0;

    double b[0][0] = -1.0;
    double b[0][1] = -7.0;
    double b[0][2] = -12.0;
    double b[0][3] = 2.0;

    FILE *fp;

    fp = fopen("input.dat", "W");

    fprintf(fp, "%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", a[0][0], a[0][1], a[0][2], a[0][3], 
    a[1][0], a[1][1], a[1][2], a[1][3], a[2][0], a[2][1], a[2][2], a[2][3], a[3][0], a[3][1], a[3][2], a[3][3]);
    fprintf(fp, "\n");
    fprintf(fp, "%f %f %f %f\n", b[0][0], b[0][1], b[0][2], b[0][3]);

    printf("%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", a[0][0], a[0][1], a[0][2], a[0][3], 
    a[1][0], a[1][1], a[1][2], a[1][3], a[2][0], a[2][1], a[2][2], a[2][3], a[3][0], a[3][1], a[3][2], a[3][3]);
    printf("\n");
    printf("%f %f %f %f\n", b[0][0], b[0][1], b[0][2], b[0][3]);

    fclose(fp);

    return 0;
}