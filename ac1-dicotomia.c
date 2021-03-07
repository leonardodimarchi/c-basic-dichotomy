#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void alocarFloat(float **p, int quantidade);
void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao);

int main(){
    int quantidadeDeTermos;
    float *precisao = NULL;
    float *coeficientes = NULL;
    float *expoentes = NULL;
    float *intervaloDoisValores = NULL;

    alocarFloat(&intervaloDoisValores, 2);

    printf("\nDicotomia\n\n");

    printf("Quantidade de termos da equacao (no maximo 10): ");
    scanf("%i",&quantidadeDeTermos);

    alocarFloat(&coeficientes,quantidadeDeTermos);
    alocarFloat(&expoentes,quantidadeDeTermos);
    alocarFloat(&precisao,1);

    receberParametros(coeficientes,expoentes,quantidadeDeTermos,intervaloDoisValores,precisao);

    system("PAUSE");
    return(0);
}

void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao){
    int contador;

    printf("\n\n");

    for(contador = 0; contador < quantidadeDeTermos; contador++){
        printf("Valores para \'x\' no %i\xA7 termo (coeficiente expoente): ",contador+1);
        scanf("%f %f",coeficientes+contador, expoentes+contador);
    }

    printf("Intervalo [Entre virgulas: x1,x2]: ");
    scanf("%f,%f",intervalo,(intervalo+1));

    printf("Precisao (Exemplo: 0.01): ");
    scanf("%f",precisao);

}

void alocarFloat(float **p, int quantidade){
    if((*p = (float *)realloc(*p, quantidade*sizeof(float)) ) == NULL){
        printf("\nOcorreu um erro na alocacao (Float)");
        exit(1);
    }
    printf("\nFloat Alocado com sucesso - End= %u", *p);
}