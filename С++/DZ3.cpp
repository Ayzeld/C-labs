#include <iostream>
#include <cstdlib>
#include <ctime>

// Заполняем массив возрастающими числами
void FillInc(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
}

// Заполняем массив убывающими числами
void FillDec(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i - 1;
    }
}

// Заполняем массив случайными числами
void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}

// Контрольная сумма
int CheckSum(int A[], int n) {
    int summ = 0;
    for (int i = 0; i < n; i++) {
        summ += A[i];
    }
    return summ;
}

// Считаем серии
int RunNumber(int A[], int n) {
    if (n == 0) return 0;
    int series = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            series++;
        }
    }
    return series;
}

// Выводим массив
void PrintMas(int A[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Шейкерная сортировка
void ShakerSort(int A[], int n, int& M, int& C) {
    int left = 0, right = n - 1;
    bool swapped = true;
    M = 0; // Количество пересылок
    C = 0; // Количество сравнений

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            C++;
            if (A[i] > A[i + 1]) {
                std::swap(A[i], A[i + 1]);
                M += 3; // 3 пересылки (swap)
                swapped = true;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            C++;
            if (A[i] < A[i - 1]) {
                std::swap(A[i], A[i - 1]);
                M += 3; // 3 пересылки (swap)
                swapped = true;
            }
        }
        left++;
    }
}

int main() {
    const int n = 15;
    int A[n];
    int M, C; // Переменные для подсчёта пересылок и сравнений
    srand(static_cast<unsigned>(time(0))); // Инициализируем генератор

    // Возрастающий массив
    std::cout << "Возрастающий массив: ";
    FillInc(A, n);
    PrintMas(A, n);
    ShakerSort(A, n, M, C);
    std::cout << "После ShakerSort: ";
    PrintMas(A, n);
    std::cout << "Пересылки (M): " << M << ", Сравнения (C): " << C << std::endl;
    std::cout << "Серия: " << RunNumber(A, n) << std::endl;
    std::cout << "Контрольная сумма: " << CheckSum(A, n) << std::endl;

    // Убывающий массив
    std::cout << "Убывающий массив: ";
    FillDec(A, n);
    PrintMas(A, n);
    ShakerSort(A, n, M, C);
    std::cout << "После ShakerSort: ";
    PrintMas(A, n);
    std::cout << "Пересылки (M): " << M << ", Сравнения (C): " << C << std::endl;
    std::cout << "Серия: " << RunNumber(A, n) << std::endl;
    std::cout << "Контрольная сумма: " << CheckSum(A, n) << std::endl;

    // Случайный массив
    std::cout << "Рандомный массив: ";
    FillRand(A, n);
    PrintMas(A, n);
    ShakerSort(A, n, M, C);
    std::cout << "После ShakerSort: ";
    PrintMas(A, n);
    std::cout << "Пересылки (M): " << M << ", Сравнения (C): " << C << std::endl;
    std::cout << "Серия: " << RunNumber(A, n) << std::endl;
    std::cout << "Контрольная сумма: " << CheckSum(A, n) << std::endl;
    return 0;
}
