//lib.c
#include "head.h"

// создание студента
Student addStudent(const char *name, int math, int phy, int inf) {
    Student newStudent;
    strncpy(newStudent.name, name, 63);
    newStudent.name[63] = '\0';
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

// вывод инфы
void printStudentInfo(Student s) {
    printf("Имя: %s, Математика: %d, Физика: %d, Информатика: %d, Общий балл: %d\n",
           s.name, s.math, s.physics, s.informatics, s.total);
}

// сортировка вставками по убыванию
void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].total < key.total) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Radix Sort
int getMax(Student arr[], int n) {
    int max = arr[0].total;
    for (int i = 1; i < n; i++)
        if (arr[i].total > max)
            max = arr[i].total;
    return max;
}

void countingSort(Student arr[], int n, int exp) {
    Student output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i].total / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i].total / exp) % 10] - 1] = arr[i];
        count[(arr[i].total / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(Student arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}