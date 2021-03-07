#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void alocarFloat(float **p, int quantidade);
void receberParametros(float *termos, float *expoentes, int quantidadeDeTermos);

int main(){
    int quantidadeDeTermos;
    float *termos = NULL;
    float *expoentes = NULL;

    printf("\nDicotomia\n\n");

    printf("Quantidade de termos da equacao (no maximo 10): ");
    scanf("%i",&quantidadeDeTermos);

    alocarFloat(&termos,quantidadeDeTermos);
    alocarFloat(&expoentes,quantidadeDeTermos);

    receberParametros(termos,expoentes,quantidadeDeTermos);
    
    system("PAUSE");
    return(0);
}

void receberParametros(float *termos, float *expoentes, int quantidadeDeTermos){
    int contador;

    for(contador = 0; contador < quantidadeDeTermos; contador++){
        printf("\nValores para \'x\' no %i\xA7 termo (coeficiente expoente): ",contador+1);
        scanf("%f %f",termos+contador, expoentes+contador);
    }
}

void alocarFloat(float **p, int quantidade){
    if((*p = (float *)realloc(*p, quantidade*sizeof(float)) ) == NULL){
        printf("\nOcorreu um erro na alocacao (Float)");
        exit(1);
    }
    printf("\nFloat Alocado com sucesso - End= %u", *p);
}