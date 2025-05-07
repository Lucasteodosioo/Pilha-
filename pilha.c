#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
}No;

int ler_num(){
    int num;
    printf("Digite o numero que voce deseja inserir: \n");
    scanf("%d", &num);
    return num;
}

void push(No **pilha){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo->num = ler_num();
        novo->prox = *pilha;
        *pilha = novo;
    }  
    else
        printf("Erro ao alocar memoria.\n");
}

void pop (No **pilha){
    if (*pilha == NULL){
        printf("Pilha vazia.\n");
        return;
    }
    No *aux = *pilha;
    *pilha = aux->prox;
    free(aux);
}

void imprimir(No *pilha){
    if (pilha == NULL){
        printf("A pilha esta vazia.\n");
    }
    while(pilha){
        printf("%d ", pilha->num);
        pilha = pilha->prox;
    }
    printf("\n");
}

int main(){
    No *p = NULL;
    int opcao;

    while(1){
        printf("1 inserir - 2 remover - 3 imprimir - 0 imprimir.\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            push(&p);            
            break;
        case 2:
            pop(&p);
            break;
        case 3: 
            imprimir(p);  
            break;  
        case 0:
            return 0;
        }
    }
    
    return 0;
}