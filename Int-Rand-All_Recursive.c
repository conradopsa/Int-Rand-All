#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int alimentarSeed = 1;

int intRand(int i1, int i2){
    /*Gera números alétorios entre i1 e 12*/

    //Alimentando seed
    if (alimentarSeed){
        srand((unsigned int)time(NULL));
        alimentarSeed = 0;
    }

    //i1 --> intervalo fechado inicial (menor)
    //i2 --> intervalo fechado final (maior)
    
    //Corrigindo qual variável é final e qual é inicial
    if (i1>i2)
        troca(&i1, &i2);


    return i1 + (rand() % ( (i2+1) - i1));
}

//Tamanho de alocação do retorno de intRandAll()
#define RDALL_ALLOC 10000

char * retorno;

//Função recursiva que trará o retorno
void intRdAllRec(int i1, int i2){
    int rd = intRand(i1, i2);
    
    //rd para string
    char rdStr[5];
    sprintf(rdStr, "%d, ", rd);
    
    //Concatenando Retorno
    strcat(retorno, rdStr);

    if (i1==i2)
        return;
    else
    {
        int k1=rd-1, k2=rd+1;

        if (k1 >= i1)
            intRdAllRec(i1, k1);
            
        if (k2 <= i2)
            intRdAllRec(k2, i2);
    }
    
}

char * intRandAll(int i1, int i2){

    //Preparando Variavel de Retorno (Saida)
    if (retorno != NULL)
        free(retorno);

    retorno = (char *)malloc(RDALL_ALLOC);

    //Corrigindo qual variável é final e qual é inicial
    if (i1>i2)
        troca(&i1, &i2);

    //Algoritmo Recursivo
    intRdAllRec(i1, i2);

    return retorno;
}

int main(){

    int a=10, b=20;
    printf("Intervalo [%d, %d]:\n", a, b);
    printf("%s\n", intRandAll(a, b));

}