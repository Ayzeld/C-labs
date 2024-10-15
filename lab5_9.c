#include<stdio.h>

int main() {
    char a;
    printf("Введите число: ");
    scanf("%d", &a);
    for (int i = 0; i < sizeof(a)*8 ; i++) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");

}
