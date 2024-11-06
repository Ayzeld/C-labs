#include <stdio.h>

void print_array(int n, int array[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n=0;
    printf("Введите размер массив: ");
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) {
        printf("Введите элемент массива: ");
        scanf("%d", &a[i]);
    }
    print_array(n, a);
    int m1=0,m2=0,p1=0,p2=0,s=0;
    for (int i=0; i < n; i++) {
        if ((i%2 == 0) && (a[i]<0)) {
            m1++;}
        if ((i%2 != 0) && (a[i]<0)) {
            m2++;}
        if ((i%2 == 0) && (a[i]>=0)) {
            p1++;}
        if ((i%2 != 0) && (a[i]>=0)) {
            p2++;}
    }
    if (m1+p2==n || m2+p1==n) {
        for (int i=0; i<n; i++) {
            if (a[i]<0) {
                a[i]=0;
            }
        }
    }
    else {
        for (int i=0; i<n; i++) {
            if (a[i]>=0) {
                a[i]=0;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (a[i]%2 != 0) {
            s=s+1;
        }
    }
    print_array(n, a);
    printf("%d", s);
}
