#include <stdio.h>
#include <stdlib.h>

double determinant2x2(double a, double b, double c, double d) {
    return a * d - b * c;}

double determinant3x3(double a[3][3]) {

    return a[0][0] * ((a[1][1] * a[2][2]) - (a[1][2] * a[2][1])) -
           a[0][1] * ((a[1][0] * a[2][2]) - (a[1][2] * a[2][0])) +
           a[0][2] * ((a[1][0] * a[2][1]) - (a[1][1] * a[2][0]));
           }

int solve2x2(double a[2][2], double b[2], double x[2]) {
    double det = determinant2x2(a[0][0], a[0][1], a[1][0], a[1][1]);
    printf("%d \n", det);
    if (det == 0) return 0;
    x[0] = determinant2x2(b[0], a[0][1], b[1], a[1][1]) / det;
    x[1] = determinant2x2(a[0][0], b[0], a[1][0], b[1]) / det;
    return 1;}

int solve3x3(double a[3][3], double b[3], double x[3]) {
    double det = determinant3x3(a);
    printf("%d \n", det);
    if (det == 0) return 0;
    double a_x[3][3], a_y[3][3], a_z[3][3];
    for (int i = 0; i < 3; i++) {
        a_x[i][0] = b[i];
        a_y[i][1] = b[i];
        a_z[i][2] = b[i];
        for (int j = 1; j < 3; j++) a_x[i][j] = a[i][j];
        for (int j = 0; j < 3; j++) if (j != 1) a_y[i][j] = a[i][j];
        for (int j = 0; j < 3; j++) if (j != 2) a_z[i][j] = a[i][j];
    }
    x[0] = determinant3x3(a_x) / det;
    x[1] = determinant3x3(a_y) / det;
    x[2] = determinant3x3(a_z) / det;
    return 1;}

int main() {
    int n;
    printf("Введите размерность системы (2 или 3): ");
    scanf("%d", &n);
    if (n != 2 && n != 3) {
        printf("Поддерживаются только системы 2x2 и 3x3.\n");
        return 1;
    }
    double a[3][3], b[3], x[3];
    printf("Введите матрицу коэффициентов:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    printf("Введите вектор свободных членов:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    if (n == 2) {
        if (solve2x2(a, b, x)) {
            printf("Решение СЛАУ 2x2:\nx1 = %f\nx2 = %f\n", x[0], x[1]);
        } else {
            printf("Система не имеет единственного решения.\n");
        }
    } else {
        if (solve3x3(a, b, x)) {
            printf("Решение СЛАУ 3x3:\nx1 = %f\nx2 = %f\nx3 = %f\n", x[0], x[1], x[2]);
        } else {
            printf("Система не имеет единственного решения.\n");
        }
    }
    return 0;
}
