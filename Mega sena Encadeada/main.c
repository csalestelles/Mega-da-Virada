
//                                                 Gerador de jogos da Mega sena

//  Created by Caio Arthur.
//  Copyright © 2015 Caio Arthur. All rights reserved.
//


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

node *LISTA, *listarep;

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

int Num(int x){
    return rand()%x;
}

void GeraAleatorio(int inserido){
    if (inserido < 10){
        valor = 1 + Num(25) - Num(20);
    }
    else if (inserido > 55){
        valor = inserido - 15 + Num(30) - Num(25);
            }
    else{
        valor = inserido - 10 + Num(30) - Num(20);
    }
    if (valor > 60 | valor<1) {
        int novoinserido = valor;
        GeraAleatorio(novoinserido);
    }

}

int ConfereValor2(int dado){
    temp1 = listarep->prox;
    while(temp1 != NULL){
        if (dado==temp1->num)
        {
            GeraAleatorio(dado);
        }
        else{temp1 = temp1->prox;}
    }
    return dado;
}


void ReproduzirSequencias(node *Cabeca){
    while (w<7){
        printf("\n\nSequencia %d: \n",w);
        while(temp!=NULL){
            GeraAleatorio(temp->num);
            Insere(listarep, ConfereValor2(valor));
            printf("%d\n", valor);
            temp = temp->prox;
        }
        w++;
        temp = LISTA->prox;
        if (w>1){
            listarep->prox = NULL;
        }
        temp1 = listarep->prox;
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

void IniciaLista(node *listas){
    listas = (node *) malloc(sizeof(node));
    listas->prox = NULL;
}

int main() {
    LISTA = (node *) malloc(sizeof(node));
    LISTA->prox = NULL;
    listarep = (node *) malloc(sizeof(node));
    listarep->prox = NULL;
    srand((unsigned) time(NULL));
    printf("Digite os valores da aposta: \n");
    Ler();
    temp=LISTA->prox;
    ReproduzirSequencias(LISTA);
    return 0;
}
