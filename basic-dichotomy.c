//Dicotomia

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h> //Biblioteca para facilitar a utilizacao de boolean

//Prototipo das funcoes
void aplicarDicotomia(float *coeficientes, float *expoentes, float *quantidadeDeTermos, float *intervalo, float *precisao);
float realizarEquacao(float x, float *coeficientes, float *expoentes, int quantidadeDeTermos);
void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao);
bool verificarRaizNoIntervalo(float intervaloInicial,float intervaloFinal,float *coeficientes,float *expoentes, int quantidadeDeTermos);
void printarLinhaTabela(int indice, float intervaloA,float pontoMedio, float intervaloB, float funcIntervaloA, float funcPontoMedio, float funcIntervaloB);
void printarEstruturaTabela();
float mediaFloat(float primeiroValor, float segundoValor);
float arredondarFloat(float valor, int numeroDeCasas);
void alocarFloat(float **p, int quantidade);

int main(){
    int quantidadeDeTermos;
    float *precisao = NULL;
    float *coeficientes = NULL;
    float *expoentes = NULL;
    float *intervaloDoisValores = NULL;

    printf("\n- - - Metodos Numericos - Dicotomia - - -\n\n");

    printf("Quantidade de termos da equacao (no maximo 10): ");
    scanf("%i",&quantidadeDeTermos);

    //Alocacoes
    alocarFloat(&coeficientes,quantidadeDeTermos);
    alocarFloat(&expoentes,quantidadeDeTermos);
    alocarFloat(&intervaloDoisValores, 2);
    alocarFloat(&precisao,1);

    receberParametros(coeficientes,expoentes,quantidadeDeTermos,intervaloDoisValores,precisao);
    aplicarDicotomia(coeficientes,expoentes,quantidadeDeTermos,intervaloDoisValores,precisao);

    system("PAUSE");
    return 0;
}

void aplicarDicotomia(float *coeficientes, float *expoentes, float *quantidadeDeTermos, float *intervalo, float *precisao){
    float pontoMedio, funcIntervaloA, funcIntervaloB, funcPontoMedio;
    int indice=1;
    bool existeRaizIntervaloAePontoMedio, existeRaizIntervaloBePontoMedio;

    printarEstruturaTabela();

    do{
        
        //Atualiza as variaveis 
        pontoMedio = arredondarFloat(mediaFloat(*intervalo, *(intervalo+1)),3);
        funcIntervaloA = realizarEquacao(*intervalo, coeficientes, expoentes, quantidadeDeTermos);
        funcIntervaloB = realizarEquacao(*(intervalo+1), coeficientes, expoentes, quantidadeDeTermos);
        funcPontoMedio = realizarEquacao(pontoMedio, coeficientes, expoentes, quantidadeDeTermos);

        printarLinhaTabela(indice,*intervalo,pontoMedio,*(intervalo+1),funcIntervaloA,funcPontoMedio,funcIntervaloB);

        //Verifica em qual metade a raiz se encontra
        existeRaizIntervaloAePontoMedio = verificarRaizNoIntervalo(*intervalo, pontoMedio, coeficientes, expoentes, quantidadeDeTermos);
        existeRaizIntervaloBePontoMedio = verificarRaizNoIntervalo(*(intervalo+1), pontoMedio, coeficientes, expoentes, quantidadeDeTermos);

        if(existeRaizIntervaloAePontoMedio){
            *(intervalo+1) = pontoMedio;
        }else if(existeRaizIntervaloBePontoMedio){
            *intervalo = pontoMedio;
        }

        indice++;
        
        //Finaliza quando o modulo de f(m) <= Precisao
    }while(fabs(funcPontoMedio)> *precisao); 

    printf("\n\nA raiz encontrada da funcao \x82 %.3f com erro de aproximadamente %.3f (< %.3f)\n\n",pontoMedio,fabs(funcPontoMedio),*precisao);

}

float arredondarFloat(float valor, int numeroDeCasas){
    return roundf(valor * pow(10,numeroDeCasas))/pow(10,numeroDeCasas);
}

float mediaFloat(float primeiroValor, float segundoValor){
    return (primeiroValor+segundoValor)/2;
}

void receberParametros(float *coeficientes, float *expoentes, int quantidadeDeTermos, float *intervalo, float *precisao){
    int contador;
    bool verificadorRaizNoIntervalo;

    printf("\n");

    //Recebe os coeficientes e expoentes
    for(contador = 0; contador < quantidadeDeTermos; contador++){
        printf("Valores para \'x\' no %i\xA7 termo (coeficiente expoente): ",contador+1);
        scanf("%f %f",coeficientes+contador, expoentes+contador);
    }

    //Recebe intervalo, corrige erros de entrada e verifica se ha raiz neste intervalo inicial.
    do{
        printf("\nIntervalo [Entre virgulas: x1,x2]: ");
        scanf("%f,%f",intervalo,(intervalo+1));

        //Se nao tiver raiz no intervalo que passou, pedir novamente.
        verificadorRaizNoIntervalo = verificarRaizNoIntervalo(*intervalo, *(intervalo+1), coeficientes, expoentes, quantidadeDeTermos);

        if(*intervalo > *(intervalo+1)){  
            printf("\nColoque o menor intervalo primeiro.\n");
        }else if(*intervalo == *(intervalo+1)){
            printf("\nDigite um intervalo valido.\n");
        }else if(!verificadorRaizNoIntervalo){
            printf("\nNao existem raizes nesse intervalo.\n");
        }

    }while(*intervalo > *(intervalo+1) || *intervalo == *(intervalo+1) || !verificadorRaizNoIntervalo);
    
    //Recebe a precisao.
    printf("Precisao (Exemplo: x.xxx): ");
    scanf("%f",precisao);
}

bool verificarRaizNoIntervalo(float intervaloInicial,float intervaloFinal,float *coeficientes,float *expoentes, int quantidadeDeTermos){

    float resultadoIntervaloInicial = realizarEquacao(intervaloInicial, coeficientes, expoentes, quantidadeDeTermos);
    float resultadoIntervaloFinal = realizarEquacao(intervaloFinal, coeficientes, expoentes, quantidadeDeTermos);
    
    //f(a)*f(b) < 0 tem raiz
    if((resultadoIntervaloInicial * resultadoIntervaloFinal) < 0 ){
        return true;
    }else{
        return false;
    }
}

float realizarEquacao(float x, float *coeficientes, float *expoentes, int quantidadeDeTermos){
    int contador;
    float expoenteAtual, coeficienteAtual, resultado = 0;

    //Loop principal, passando por todos os termos da equacao
    for(contador=0; contador<quantidadeDeTermos; contador++){

        coeficienteAtual = *(coeficientes+contador);
        expoenteAtual = *(expoentes+contador);

        //Nao tem o X
        if( expoenteAtual == 0){
            if(coeficienteAtual < 0){
                resultado += coeficienteAtual;
            }else{
                resultado+= coeficienteAtual;
            }

        //Com X
        }else{
            if(coeficienteAtual == 1){
                resultado += pow(x,expoenteAtual);
            }else if(coeficienteAtual == -1){
                resultado -= pow(x,expoenteAtual);
            }else{
                if(coeficienteAtual < 0){
                    resultado += coeficienteAtual * (pow(x,expoenteAtual));
                }else{
                    resultado += coeficienteAtual * (pow(x,expoenteAtual));
                }
            }
        }
    }

    //Retorna com 3 casas decimais
    return arredondarFloat(resultado,3);
}

void alocarFloat(float **p, int quantidade){
    if((*p = (float *)realloc(*p, quantidade*sizeof(float)) ) == NULL){
        printf("\nOcorreu um erro na alocacao (Float)");
        exit(1);
    }
}

void printarEstruturaTabela(){
    printf("\n\ti\ta\tm\tb\tf(a)\tf(m)\tf(b)\n");
}

void printarLinhaTabela(int indice, float intervaloA,float pontoMedio, float intervaloB, float funcIntervaloA, float funcPontoMedio, float funcIntervaloB){
    printf("\n\t%i\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f",indice, intervaloA, pontoMedio, intervaloB, funcIntervaloA, funcPontoMedio, funcIntervaloB);
}
