#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	for(int k = 0, m = 1; m <= n;k++,m=m*2)
	{
		printf("%d ",k-1);
	}

}
