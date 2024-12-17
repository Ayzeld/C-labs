#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Manual(int matrix[][100], int rows, int cols) { // Заполнение матрицы вручную
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void Random(int matrix[][100], int rows, int cols) { // Заполнение матрицы случайными числами
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 - 50;
        }
    }
}

void Sort(int matrix[][100], int rows, int cols) { // Сортировка матрицы в порядке убывания
  int temp;
  int arr[rows * cols];
  int k=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[k++] = matrix[i][j];
        }
    }
  for (int i = 0; i < rows * cols-1; i++) {
    for (int j = 0; j < rows*cols-i-1; j++) {
      if (arr[j] < arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  k=0;
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = arr[k++];
        }
    }

}

int main() {
    int rows, cols;
    printf("Введите количество строк матрицы: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов матрицы: ");
    scanf("%d", &cols);
    int matrix[100][100];
    char choice;
    printf("Заполнить матрицу вручную (m) или случайными числами (r)? ");
    scanf(" %c", &choice);
    if (choice == 'm') {
        Manual(matrix, rows, cols);
    } else if (choice == 'r') {
        Random(matrix, rows, cols);
    } else {
        printf("Неверный выбор.\n");
        return 1;
    }
    Sort(matrix, rows, cols);
    int sum = 0;
    int n = 0;
    for (int i = rows / 2; i < rows; i++) {
        for (int j = cols / 2; j < cols; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
            }
        }
    }
   for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[i][j]);
      if ((i < rows/2 && j < cols/2) || (i >= rows/2 && j >= cols/2)) continue;
      if(matrix[i][j] == 0){
        n = 1;
      }
    }
    printf("\n");
  }
    printf("Сумма полож. элементов четверти: %d\n", sum);
    if(n){
        printf("В матрице вне границ квадрата есть нули.\n");
    } else {
      printf("В матрице вне границ квадрата нет нулей.\n");
    }
    return 0;
}