#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void alocarFloat(float **p, int quantidade);
void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao);
bool verificarRaizNoIntervalo(float intervaloInicial,float intervaloFinal,float *coeficientes,float *expoentes, int quantidadeDeTermos);

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

    //f(a)*f(b) < 0
    //verificarRaizNoIntervalo(float *intervaloDoisValores, float *(intervaloDoisValores+1)); 
    //if(intervalo1*intervalo2 < 0) return true else return false 
    //Se nao tiver raiz no intervalo que passou, pedir novamente.

    system("PAUSE");
    return(0);
}

void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao){
    int contador;
    bool verificadorRaizNoIntervalo;

    printf("\n\n");

    for(contador = 0; contador < quantidadeDeTermos; contador++){
        printf("Valores para \'x\' no %i\xA7 termo (coeficiente expoente): ",contador+1);
        scanf("%f %f",coeficientes+contador, expoentes+contador);
    }

    //Receber intervalo e verificar se há raiz.
    do{
        printf("Intervalo [Entre virgulas: x1,x2]: ");
        scanf("%f,%f",intervalo,(intervalo+1));

        verificadorRaizNoIntervalo = verificarRaizNoIntervalo(*intervalo, *(intervalo+1), coeficientes, expoentes, quantidadeDeTermos);

        if(*intervalo > *(intervalo+1)){
            printf("\nColoque o menor intervalo primeiro.\n");
        }else if(*intervalo == *(intervalo+1)){
            printf("\nDigite um intervalo valido.\n");
        }else if(!verificadorRaizNoIntervalo){
            printf("Nao existem raizes nesse intervalo.");
        }

    }while(*intervalo > *(intervalo+1) || *intervalo == *(intervalo+1) || !verificadorRaizNoIntervalo);
    
    printf("Precisao (Exemplo: x.xxx): ");
    scanf("%f",precisao);
}

bool verificarRaizNoIntervalo(float intervaloInicial,float intervaloFinal,float *coeficientes,float *expoentes, int quantidadeDeTermos){
    
    int contador;

    for(contador=0; contador<quantidadeDeTermos; contador++){
       
    }

}

void alocarFloat(float **p, int quantidade){
    if((*p = (float *)realloc(*p, quantidade*sizeof(float)) ) == NULL){
        printf("\nOcorreu um erro na alocacao (Float)");
        exit(1);
    }
    printf("\nFloat Alocado com sucesso - End= %u", *p);
}