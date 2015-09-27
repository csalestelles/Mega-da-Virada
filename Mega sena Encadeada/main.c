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
int Ler();


void AlocaValor(encad *ale, int valor){
    ale = (encad *) malloc(sizeof(encad));
    ale->dado = valor , ale->prox = NULL, temp1 = ale;
}

void InsereLista(encad *ale1,int dado){
    AlocaValor(ale1, dado);
    if (x==1){
        Cabeca->prox = temp1;
        temp = Cabeca->prox;
    }
    else if (x==2){
        temp->prox = temp1;
    }
    else{
        temp = temp->prox;
        temp->prox = temp1;
    }
}

void ConfereValor(int dado){
    if(x!=1){
        if (temp->dado==temp1->dado){
            temp->prox = NULL;
            printf("\nValor ja utilizado\n");
            Ler();
        }
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
        srand((unsigned)time(NULL));
        while(temp!=NULL){
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
int Ler(){
    Cabeca = (encad *) malloc(sizeof(encad));
    Cabeca->prox = NULL;
    if (x<7){
        printf("Digite o valor %d da aposta: ", x);
        scanf("%d", &dado);
        InsereLista(Sequencia, dado);
        ConfereValor(dado);
        x++;
        Ler();
    }
    return 0;
}


int main() {
    Ler();
    PrintDaLista(Cabeca);
    temp=Cabeca->prox;
    ReproduzirSequencias(Cabeca);
    return 0;
}
