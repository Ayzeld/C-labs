#include <stdio.h>

int main(){
	int a = 1231748;
	int s;
	int n;
	int k=0;
	for (n=a,s=0; n!=0; n=n/10){
		k=n%10;
		if (k>s){
			s=k;
		}
	}
	printf("%d \n",s);
}
