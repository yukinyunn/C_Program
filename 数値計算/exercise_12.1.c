#include <stdio.h>

typedef struct complex{
    double real;
    double img;
} complex_t;

void complex_swap(complex_t *a, complex_t *b);

int main (void) {
    complex_t a = {1.2, 2.3}, b = {3.1, 4.5};

    printf("a=(%f+%fi) \t b=(%f+%fi)\n", a.real, a.img, b.real, b.img);
    complex_swap(&a, &b);  //2つの複素数の入れ替え
    printf("a=(%f+%fi) \t b=(%f+%fi)\n", a.real, a.img, b.real, b.img);

    return 0;
}

void complex_swap(complex_t *a, complex_t *b) {
    complex_t tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}