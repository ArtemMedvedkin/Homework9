#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define COL 9
#define ROW 9

int zd3();

int main() {
	setlocale(LC_CTYPE, ".UTF-8");

	zd3();

	return 0;
}
//int zd3() {
//
//    double a, b, c;
//    char symbol;
//
//    double h,pp,S,sinus;
//
//    int kol, koef;
//
//    printf("Введи длины сторон a, b, c: ");
//    scanf("%lf %lf %lf", &a, &b, &c);
//
//    printf("Введи символ: ");
//    scanf(" %c", &symbol);
//
//    if (a <= 0 || b <= 0 || c <= 0 || a >= b + c || a <= abs(b - c) || b >= a + c || c >= a + b) {
//
//        printf("Треугольник с такими сторонами не существует либо не подхожит по условию.\n");
//    }
//
//    pp = (a + b + c) / 2.0;
//    S = sqrt(pp*(pp - a)*(pp - b)*(pp - c));
//    h = (2.0 * S) / a;
//    sinus = h / c;
//    koef = sinus * 2;
//
//    putchar(symbol);
//    for (kol = 1; kol < h; ++kol) {
//        printf("%*c%*c", koef, symbol, koef, symbol);
//    }
//
//}
int zd3() {


    double a, b, c;
    double pp, S, h;
    double x;
    char symbol;




    int masshtab = 3;
    int shirina, vysota;
    int kol, levo, pravo;
    int i, probel;




    printf("Введи сторны a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Ошибка ввода.\n");
        return 0;
    }

    printf("Введи символ: ");
    scanf(" %c", &symbol);

    if (a <= 0 || b <= 0 || c <= 0 || a >= b + c || b >= a + c || c >= a + b) {
        printf("Треугольник с такими сторонами не существует либо не подхожит по условию.\n");
        return 0;
    }

    pp = (a + b + c) / 2.0;
    S = sqrt(pp * (pp - a) * (pp - b) * (pp - c));

    h = 2.0 * S / a;

    x = (a * a + c * c - b * b) / (2.0 * a);

    shirina = (int)(a * masshtab + 0.5);
    vysota = (int)(h * masshtab + 0.5);

    if (shirina < 2 || vysota < 2 || shirina > 150 || vysota > 100) {
        printf("Размер не подходит для консоли.\n");
        return 0;
    }

    for (kol = 0; kol < vysota; kol++) {
        levo = (int)(masshtab * x * (1.0 - (double)kol / vysota) + 0.5);

        pravo = (int)(masshtab * (x + (a - x) * (double)kol / vysota) + 0.5);

        if (levo < 0)
            levo = 0;

        if (pravo > shirina)
            pravo = shirina;

        for (i = 0; i < levo; i++) {
            printf(" ");
        }



        printf("%c", symbol);



        probel = pravo - levo - 1;



        if (probel > 0) {
            for (i = 0; i < probel; i++) {
                printf(" ");
            }

            printf("%c", symbol);
        }

        printf("\n");
    }



    for (i = 0; i <= shirina; i++) {
        printf("%c", symbol);
    }


    printf("\n");

    return 0;
}