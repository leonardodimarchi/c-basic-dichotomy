#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
//Funções
void recebeParametros(float *p);
float calculaDelta(float *p);
void calculaRaizes(float *p,float *r,float d);
void mostraRaizes(float *r);
void alocaFloat(float **p,int tam);

int main() 
{	
	float *vet=NULL,*raiz=NULL,delta;
    
    alocaFloat(&vet,3);
    alocaFloat(&raiz,2);
	
	recebeParametros(vet);
	delta = calculaDelta(vet);
	if(delta<0)
	{
		printf("Raiz nao real.\n");
	}
	else
	{
		calculaRaizes(vet,raiz,delta);
		mostraRaizes(raiz);
	}    
	
	system("PAUSE");
	return 0;
}

void recebeParametros(float *p)
{
	int i;
	
	for(i=0;i<3;i++)
	{
		printf("Digite o valor de %c: ",'a'+i);
		scanf("%f",p+i);
	}
}

float calculaDelta(float *p)
{
	float d;
	d+=pow(*(p+1),2)-4**(p)**(p+2);
	return d;
}

void calculaRaizes(float *p,float *r,float d)
{
	*(r)=(-*(p+1)+sqrt(d))/(2**(p));
	*(r+1)=(-*(p+1)-sqrt(d))/(2**(p));
}

void mostraRaizes(float *r)
{
	int i;
	
	for(i=0;i<2;i++)
	{
		printf("Raiz %i: %.2f\n",i+1,*(r+i));
	}
}

void alocaFloat(float **p, int tam)
{
	if( (*p=(float *)realloc(*p,tam*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n",*p);
}	
