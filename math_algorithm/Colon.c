#include <stdio.h>
#include <math.h>

const double PI = 3.14159265358979;
double A, B, H, M;

int main () {
    scanf("%lf%lf%lf%lf", &A, &B, &H, &M);
    
    double Angle_H = 30.0*H + 0.5*M;
    double Angle_M = 6.0*M;
    double Hx = A*cos(Angle_H * PI/180.0);
    double Hy = A*sin(Angle_H * PI/180.0);
    double Mx = B*cos(Angle_M * PI/180.0);
    double My = B*sin(Angle_M * PI/180.0);

    double d = sqrt((Hx-Mx)*(Hx-Mx) + (Hy-My)*(Hy-My));
    
    printf("%.12lf\n", d);

    return 0;
}