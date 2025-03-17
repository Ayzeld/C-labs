#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Заполнение массива возрастающими числами
void FillInc(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
}

// Заполнение массива убывающими числами
void FillDec(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i - 1;
    }
}

// Заполнение массива случайными числами
void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}

// Подсчёт контрольной суммы
int CheckSum(int A[], int n) {
    int summ = 0;
    for (int i = 0; i < n; i++) {
        summ += A[i];
    }
    return summ;
}

// Подсчёт количества серий
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

// Сортировка методом прямого включения с подсчётом операций
void InsertSort(int A[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            comparisons++;
            A[j + 1] = A[j];
            swaps++;
            j--;
        }
        comparisons++; // Сравнение при выходе из цикла
        A[j + 1] = key;
        swaps++;
    }
}

// Вывод массива
void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 15;
    int A[n];
    int comparisons, swaps;
    srand(time(0));

    cout << "Возрастающий массив: ";
    FillInc(A, n);
    PrintArray(A, n);
    InsertSort(A, n, comparisons, swaps);
    cout << "Сравнения: " << comparisons << ", Пересылки: " << swaps << endl;

    cout << "Убывающий массив: ";
    FillDec(A, n);
    PrintArray(A, n);
    InsertSort(A, n, comparisons, swaps);
    cout << "Сравнения: " << comparisons << ", Пересылки: " << swaps << endl;

    cout << "Случайный массив: ";
    FillRand(A, n);
    PrintArray(A, n);
    InsertSort(A, n, comparisons, swaps);
    cout << "Сравнения: " << comparisons << ", Пересылки: " << swaps << endl;

    return 0;
}
