# include <stdio.h>


int main()
{
	int tem;
	char ed;
	printf("Temperature(f,c): ");
	scanf("%d %c",&tem,&ed);
	if(ed=='c')
	{
	 printf("%.1f f \n", tem*1.8+32);
	}
	else if (ed=='f')
	{
	 printf("%.1f c \n", tem/1.8-32);
	}
}
