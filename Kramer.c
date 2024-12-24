#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9 

double determinant2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

double determinant3x3(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int solve2x2(double a[2][2], double b[2], double x[2]) {
    double det = determinant2x2(a[0][0], a[0][1], a[1][0], a[1][1]);
    if (fabs(det) < EPSILON) return 0;
    x[0] = determinant2x2(b[0], a[0][1], b[1], a[1][1]) / det;
    x[1] = determinant2x2(a[0][0], b[0], a[1][0], b[1]) / det;
    return 1;
}

int solve3x3(double a[3][3], double b[3], double x[3]) {
    double det = determinant3x3(a);
    if (fabs(det) < EPSILON) return 0;
    double temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) temp[i][j] = (j == 0) ? b[i] : a[i][j];
    }
    x[0] = determinant3x3(temp) / det;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) temp[i][j] = (j == 1) ? b[i] : a[i][j];
    }
    x[1] = determinant3x3(temp) / det;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) temp[i][j] = (j == 2) ? b[i] : a[i][j];
    }
    x[2] = determinant3x3(temp) / det;
    return 1;
}

int main() {
    int n;
    printf("Введите размерность системы (2 или 3): ");
    scanf("%d", &n);
    if (n != 2 && n != 3) {
        printf("Поддерживаются только системы 2x2 и 3x3.\n");
        return 1;
    }
    double a[3][3] = {0}, b[3] = {0}, x[3] = {0};
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
            printf("Решение:\nx1 = %.2f\nx2 = %.2f\n", x[0], x[1]);
        } else {
            printf("Система не имеет единственного решения.\n");
        }
    } else {
        if (solve3x3(a, b, x)) {
            printf("Решение:\nx1 = %.2f\nx2 = %.2f\nx3 = %.2f\n", x[0], x[1], x[2]);
        } else {
            printf("Система не имеет единственного решения.\n");
        }
    }
    return 0;
}
