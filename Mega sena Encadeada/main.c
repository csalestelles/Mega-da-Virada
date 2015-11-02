//
//  main.c
//  Mega sena Encadeada
//
//  Created by Caio Arthur on 21/09/15.
//  Copyright © 2015 Caio Arthur. All rights reserved.
//

//Definicao das Variaveis globais


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;

node *temp, *temp1;
int dado, x=1, w=1, valor;
void Ler();


int vazia(node *LISTA)
{
    if(LISTA->prox == NULL)
        return 1;
    else
        return 0;
}

node *LISTA;

void Insere(node *LISTA, int valor)
{
    node *novo=(node *) malloc(sizeof(node));
    novo->num = valor;
    novo->prox = NULL;
    
    if(vazia(LISTA)){
        LISTA->prox=novo;
    }
    else{
        node *tmp = LISTA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void Imprime(node *LISTA){
    temp = LISTA->prox;
    while (temp!=NULL) {
        printf("\n%d\n", temp->num);
        temp=temp->prox;
    }
    
}

void ConfereValor(int dado){
    temp = LISTA->prox;
    if (dado<0 | dado>60){
        printf("\nValor fora da área de marcação\n");
        Ler();
    }
    while(temp != NULL){
        if (dado==temp->num)
        {
            printf("\nValor já inserido\n");
            Ler();
        }
        else{temp = temp->prox;}
    }
}


void ReproduzirSequencias(node *Cabeca){
    while (w<3){
        printf("\n\nSequencia %d: \n",w);
        srand( time(NULL));
        while(temp!=NULL){
            srand( time(NULL));
            if(temp->num < 10){
                valor = temp->num - temp->num + 1 + (rand()%20);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            else if(temp->num > 55){
                valor = temp->num - 15 + (rand()%15);
                printf("%d\n", valor);
                temp = temp->prox;
            }
            else{
                valor = temp->num - 5 + (rand()%11);
                printf("%d\n", valor);
                temp = temp->prox;
            }
        }
        w++;
        temp = LISTA->prox;
    }
}
void Ler(){
    if (x<7){
        printf("\n%d :     ", x);
        scanf("%d", &dado);
        ConfereValor(dado);
        Insere(LISTA, dado);
        x++;
        Ler();
    }
    
}


int main() {
    LISTA = (node *) malloc(sizeof(node));
    LISTA->prox = NULL;
    printf("Digite os valores da aposta: \n");
    Ler();
    temp=LISTA->prox;
    ReproduzirSequencias(LISTA);
    return 0;
}
