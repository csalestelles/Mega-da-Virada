//
//  main.c
//  Mega sena Encadeada
//
//  Created by Caio Arthur on 21/09/15.
//  Copyright © 2015 Caio Arthur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Encadeado{
    int dados;
    struct Encadeado *prox;
};
typedef struct Encadeado encad;

//Definicao das Variaveis globais
encad *temp , *temp1, *Cabeca;
int dado, x=1, w=1, valor;
void Ler();


void AlocaValor(encad *aleatorio, int inteiro){
    aleatorio = (encad *) malloc(sizeof(encad));
    aleatorio->dados = inteiro , aleatorio->prox = NULL;
}

void SalvaSequencia(encad *ale2, int valor1){
    AlocaValor(ale2, valor1);
    Cabeca->prox = ale2;
    temp = Cabeca->prox;
}

void SalvaSequencia1(encad *ale2, int valor2){
    AlocaValor(ale2, valor2);
    temp->prox = ale2;
    temp = ale2;
}
void EscolheFunc(int x){
    if (x==1){
        encad *Sequencia;
        SalvaSequencia(Sequencia, dado);
    }
    else{
        encad *Sequencia1;
        SalvaSequencia1(Sequencia1, dado);
    }
}

void ConfereValor(int dado){
    temp = Cabeca->prox;
    while(temp->prox != NULL){
        if (dado==temp->dados)
        {
            printf("\nValor já inserido\n");
            Ler();
        }
        temp = temp->prox;
    }
}

void PrintDaLista(encad *encad){
    temp=encad->prox;
    while(temp!=NULL){
        printf("%d", temp->dados);
        temp=temp->prox;
    }
}

void ReproduzirSequencias(encad *Cabeca1){
    while (w<11){
        printf("\n\nSequencia %d: \n",w);
        while(temp!=NULL){
            srand((unsigned)time(NULL));
            if(temp->dados<6){
                valor = temp->dados - temp->dados + 1 + (rand()%10);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            if(temp->dados>55){
                valor = temp->dados - 4 + (rand()%8);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            else{
                valor = temp->dados - 5 + (rand()%11);
                printf("%d\n", valor);
                temp = temp->prox;
            }
        }
        w++;
    }
}
void Ler(){
    if (x<7){
        printf("\n%d :     ", x);
        scanf("%d", &dado);
        if (x!=1){
            ConfereValor(dado);
        }
        EscolheFunc(x);
        x++;
        Ler();
    }
    
}


int main() {
    Cabeca = (encad *) malloc(sizeof(encad));
    printf("Digite os valores da aposta: \n");
    Ler();
    PrintDaLista(Cabeca);
    temp=Cabeca->prox;
    ReproduzirSequencias(Cabeca);
    return 0;
}
