#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
int main() 
{	
	float a,b,c,x1,x2,d;
	
	printf("Digite os paramentros da equacao:");
	scanf("%f %f %f",&a,&b,&c);	
		
	d=pow(b,2)-4*a*c;
	
	printf("\nDelta %f",d);
	
	if(d<0)
	{
		printf("Raiz nao real.");
	}
	else
	{
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
	
		printf("\n\nRaiz = %.2f",x1); 
		printf("\nRaiz = %.2f\n\n",x2);
	}

	
	system("PAUSE");
	return 0;
}
