#include <stdio.h>

int main() {
	char a='A';
	for (int k=0; k<5; k++) {
		for (int m=0; m<k; m++) {
			printf(" ");
		}
		for (int m=0; m<5-k; m++) {
			printf("%c", a);
		}
		printf("\n");
		a++;
	}
}
