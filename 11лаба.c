//1 не записывался адрес памяти и неправильный указатель для инит
#include <stdio.h>
#include <stdlib.h>

void init(int* arr, int n) {
    *arr = (int*)malloc(n * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; ++i) {
        (*arr)[i] = i;
    }
}

int main() {
    int* arr = NULL;
    int n = 10;
    init(&arr, n); 
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr); 
    return 0;
}

//2 было переполнение массива
#include <stdio.h>

typedef struct {
    char str[5]; 
    int num;
} NumberRepr;
void format(NumberRepr* number) {
    sprintf(number->str, "%d", number->num);
}

int main() {
    NumberRepr number = { .num = 1025 };
    format(&number);
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}

//3 sqr считал не в том порядке
#include <stdio.h>

#define SQR(x) ((x) * (x))

int main() {
    int y = 5;
    int z = SQR(y + 1);
    printf("z = %d\n", z);
    return 0;
}

//4 при подсчёте индексов с помощью for происходило переполнение
#include <stdio.h>
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) { // Изменяем условие
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int array[100] = {10, 15, 5, 4, 21, 7};
    bubble_sort(array, 6);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
