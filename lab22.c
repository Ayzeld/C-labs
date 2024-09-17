# include <stdio.h>


int main()
{
	float tem;
	char ed;
	printf("Temperature(f,c): ");
	scanf("%f %c",&tem,&ed);
	if(ed=='c'|| ed =='C')
	{
	 printf("%.4f f \n", tem*1.8+32);
	}
	else if (ed=='f' || ed=='F')
	{
	 printf("%.4f c \n", tem/1.8-32);
	}
}
