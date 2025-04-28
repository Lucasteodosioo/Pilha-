#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *next;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;

void criar_pilha(Pilha *pilha){
    pilha->topo = NULL;
    pilha->tam = 0;
}

int ler_num(){
    printf("Digite o numero que voce quer inserir na pilha: \n");
    int num;
    scanf("%d", &num);
    return num;
}

void imprimir_num(int num){
    printf("\nNumero = %d", num);
    printf("\n");
}

void push(Pilha *pilha){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo->num = ler_num();
        novo->next = pilha->topo; 
        pilha->topo = novo;
        pilha->tam++;
    }
    else
        printf("Erro ao alocar memoria.\n");
}

No* pop(Pilha *pilha){
    if (pilha->topo){
        No *aux = pilha->topo;
        pilha->topo = aux->next;
        pilha->tam--;
        return aux;
    }
    else
        printf("A pilhaesta vazia.\n");
}

void imprimir_pilha(Pilha *pilha){
    No *aux = pilha->topo;
    while (aux){
        imprimir_num(aux->num);
        aux = aux->next;
    }
}

int main(){
    int opcao;
    No *remover;
    Pilha p;

    criar_pilha(&p);
    
    while(1){
        printf("Pressio 1 para push, 2 para pop, 3 para imprimir, 0 para sair\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                push(&p);
                break;
            case 2:
                remover = pop(&p);  
                if (remover){
                    printf("Elemento removido com sucesso.\n");
                    imprimir_num(remover->num); 
                    free(remover);
                }
                else
                    printf("Nao tem o que remover.\n");
                break;
            case 3: 
                imprimir_pilha(&p);
                break;
            case 0: 
                return 0;
        }
    }    
    
    return 0;
}