#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void alocarFloat(float **p, int quantidade);
void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos);

int main(){
    int quantidadeDeTermos;
    float precisao;
    float *coeficientes = NULL;
    float *expoentes = NULL;
    float *intervaloDoisValores = NULL;

    alocarFloat(&intervaloDoisValores, 2);

    printf("\nDicotomia\n\n");

    printf("Quantidade de termos da equacao (no maximo 10): ");
    scanf("%i",&quantidadeDeTermos);

    alocarFloat(&coeficientes,quantidadeDeTermos);
    alocarFloat(&expoentes,quantidadeDeTermos);

    printf("\n\nIntervalo [x1,x2]: ");
    scanf("%f,%f",intervaloDoisValores,(intervaloDoisValores+1));

    receberParametros(coeficientes,expoentes,quantidadeDeTermos);
    
    system("PAUSE");
    return(0);
}

void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos){
    int contador;

    printf("\n\n");

    for(contador = 0; contador < quantidadeDeTermos; contador++){
        printf("Valores para \'x\' no %i\xA7 termo (coeficiente expoente): ",contador+1);
        scanf("%f %f",coeficientes+contador, expoentes+contador);
    }
}

void alocarFloat(float **p, int quantidade){
    if((*p = (float *)realloc(*p, quantidade*sizeof(float)) ) == NULL){
        printf("\nOcorreu um erro na alocacao (Float)");
        exit(1);
    }
    printf("\nFloat Alocado com sucesso - End= %u", *p);
}