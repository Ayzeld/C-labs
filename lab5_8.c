#include<stdio.h>

int main() {
	int a=0;
	int n=1;
	printf("Введите число: \n");
	scanf("%d", &a);
	while ((a&1)!=0) {
		a>>=1;
		n++;}
	printf("позиция первого нулвого бита начиная справа: %d\n", n);
}
