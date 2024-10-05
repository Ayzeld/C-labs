#include <stdio.h>

int main(){
	int a;
	int s;
	int k=0;
	int n;
  printf("Введите число: \n")
  scanf("%d", &a)
	for ( n=a, s=0; n!=0; n=n/10){
		k=n%10;
		s=s+k;
		}
	printf("%d",s);
	
}
