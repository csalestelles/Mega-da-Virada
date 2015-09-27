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
    int dado;
    struct Encadeado *prox;
};
typedef struct Encadeado encad;

encad *temp, *Cabeca, *temp1, *Sequencia;
int dado, x=1, w=1, valor;
void Ler();


void AlocaValor(encad *ale, int valor){
    ale = (encad *) malloc(sizeof(encad));
    ale->dado = valor , ale->prox = NULL;
}

void SalvaSequencia(encad *ale2, int valor1){
    AlocaValor(ale2, valor1);
    Cabeca->prox = ale2;
    temp = Cabeca->prox;
}

void SalvaSequencia1(encad *ale2, int valor1){
    AlocaValor(ale2, valor1);
    temp->prox = ale2;
    temp = ale2;
}
void EscolheFunc(int x){
    if (x==1){
        SalvaSequencia(Sequencia, dado);
    }
    else{
        SalvaSequencia1(Sequencia, dado);
    }
}

void ConfereValor(int dado){
    if (temp->dado==temp1->dado){
        temp->prox = NULL;
        printf("\nValor ja utilizado\n");
        Ler();
        }
}

void PrintDaLista(encad *encad){
    temp=encad->prox;
    while(temp!=NULL){
        printf("%d",temp->dado);
        temp=temp->prox;
    }
}

void ReproduzirSequencias(encad *Cabeca1){
    while (w<11){
        printf("\n\nSequencia %d: \n",w);
        while(temp!=NULL){
            srand((unsigned)time(NULL));
            if(temp->dado<6){
                valor = temp->dado - temp->dado + 1 + (rand()%10);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            if(temp->dado>55){
                valor = temp->dado - 4 + (rand()%8);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            else{
                valor = temp->dado - 5 + (rand()%11);
                printf("%d\n", valor);
                temp = temp->prox;
            }
        }
        w++;
    }
}
void Ler(){
    if (x<7){
        printf("Digite o valor %d da aposta: ", x);
        scanf("%d", &dado);
        EscolheFunc(x);
        if (x!=1){
            ConfereValor(dado);
        }
        x++;
        Ler();
    }
    
}


int main() {
    Cabeca = (encad *) malloc(sizeof(encad));
    Cabeca->prox = NULL;
    Ler();
    PrintDaLista(Cabeca);
    temp=Cabeca->prox;
    ReproduzirSequencias(Cabeca);
    return 0;
}
