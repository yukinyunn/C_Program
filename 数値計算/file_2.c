#include <stdio.h>

int main (void) {
    double a[4][4];
    double b[4][4];

    a[0][0] = 1.0;
    a[0][1] = -2.3;
    a[0][2] = -12.5;
    a[0][3] = 235.5;

    a[1][0] = -3.0;
    a[1][1] = 13.5;
    a[1][2] = 145.3;
    a[1][3] = -13.5;

    a[2][0] = 13.23;
    a[2][1] = 453.0;
    a[2][2] = 33.5;
    a[2][3] = 113.0;

    a[3][0] = -3.0;
    a[3][1] = 13.5;
    a[3][2] = 145.3;
    a[3][3] = -13.5;

    b[0][0] = -3.0;
    b[0][1] = 13.5;
    b[0][2] = 145.3;
    b[0][3] = -13.5;

    b[1][0] = 1.0;
    b[1][1] = -2.3;
    b[1][2] = -12.5;
    b[1][3] = 235.5;
    
    b[2][0] = 23.12;
    b[2][1] = 23.51;
    b[2][2] = 0.923;
    b[2][3] = 132.1;

    b[3][0] = 12.0;
    b[3][1] = 13.4;
    b[3][2] = 13.5;
    b[3][3] = 23.5;

    FILE *fp;

    fp = fopen("matrix_in.dat", "w");

    fprintf(fp, "%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", a[0][0], a[0][1], a[0][2], a[0][3], a[1][0], a[1][1], a[1][2], a[1][3], 
    a[2][0], a[2][1], a[2][2], a[2][3], a[3][0], a[3][1], a[3][2], a[3][3]);
    fprintf(fp, "\n");
    fprintf(fp, "%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", b[0][0], b[0][1], b[0][2], b[0][3], b[1][0], b[1][1], b[1][2], b[1][3], 
    b[2][0], b[2][1], b[2][2], b[2][3], b[3][0], b[3][1], b[3][2], b[3][3]);

    printf("%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", a[0][0], a[0][1], a[0][2], a[0][3], a[1][0], a[1][1], a[1][2], a[1][3], 
    a[2][0], a[2][1], a[2][2], a[2][3], a[3][0], a[3][1], a[3][2], a[3][3]);
    printf("\n");
    printf("%f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n", b[0][0], b[0][1], b[0][2], b[0][3], b[1][0], b[1][1], b[1][2], b[1][3], 
    b[2][0], b[2][1], b[2][2], b[2][3], b[3][0], b[3][1], b[3][2], b[3][3]);

    fclose(fp);

    return 0;
}