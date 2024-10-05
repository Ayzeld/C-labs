#include <stdio.h>

int main(){
	int a = 12345;
	int s;
	int k=0;
	int n;
	for ( n=a, s=0; n!=0; n=n/10){
		k=n%10;
		s=s*10+k;
		}
	printf("%d",s);
	
}
