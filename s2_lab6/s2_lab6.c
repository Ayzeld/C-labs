#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "head.h"

int main() {
    srand(time(NULL));
    Student students[N];
    for (int i = 0; i < N; i++) {
        char name[64];
        snprintf(name, sizeof(name), "Student_%d", i + 1);
        students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
    }
    printf("Список студентов до сортировки:\n");
    for (int i = 0; i < N; i++)
        printStudentInfo(students[i]);
    // время
    clock_t start = clock();
    insertionSort(students, N);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nСортировка вставками заняла: %f секунд\n", time_taken);
    printf("\nСписок студентов после сортировки вставками:\n");
    for (int i = 0; i < N; i++)
        printStudentInfo(students[i]);
    for (int i = 0; i < N; i++) {
        char name[64];
        snprintf(name, sizeof(name), "Student_%d", i + 1);
        students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
    }

    // время RadixSort
    start = clock();
    radixSort(students, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nПоразрядная сортировка заняла: %f секунд\n", time_taken);
    printf("\nСписок студентов после поразрядной сортировки:\n");
    for (int i = 0; i < N; i++)
        printStudentInfo(students[i]);
    return 0;
}
