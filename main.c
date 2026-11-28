#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore_nodo {
    char nome[50];
    struct arvore_nodo *esq, *dir;
} arvore_nodo;


typedef struct lista_nodo {
    char nome[50];
    struct lista_nodo *prox;
    struct arvore_nodo *atleta;

} lista_nodo;


/*
 *  ESPORTES
 */
    //permite a inserção de um esporte.
void insere_esporte(lista_nodo **init, char esporte[]) {
    lista_nodo *novo = (lista_nodo*) malloc(sizeof(lista_nodo));
    strcpy(novo->nome, esporte);
    novo->prox = NULL;
    novo->atleta = NULL;

    if(*init == NULL) {
        *init = novo;
        return;
    }
    
    novo->prox = *init;
    *init = novo;

    lista_nodo *aux = *init;
    lista_nodo *ant = NULL;
    while(aux->prox != NULL) {
        printf("\nComparando: %s com: %s", aux->nome, aux->prox->nome);
        if(strcmp(aux->nome, aux->prox->nome) < 0) {
            break;
        }
        lista_nodo *aux2 = aux->prox;
        aux->prox = aux->prox->prox;
        aux2->prox = aux;

        if(ant == NULL) {
            *init = aux2;
        } else {
            ant->prox = aux2;
        }

        ant = aux2;
    }
}

    //retorna um esporte pelo nome.
lista_nodo* busca_esporte(lista_nodo *init, char esporte[]) {
    lista_nodo *aux = init;
    while(aux != NULL) {
        if(strcmp(aux->nome, esporte) == 0) {
            return aux;
        }
        aux = aux->prox;
    }

    printf("\nNenhum esporte encontrado com nome: %s\n", esporte);
    return NULL;
}

    //escreve todos os esportes.
void listar_esportes(lista_nodo *init) {
    printf("\nLista: ");
    lista_nodo *aux = init;
    while(aux != NULL) {
        printf("%s - ", aux->nome);
        aux = aux->prox;
    }
    printf("\n");
}

    //consulta um esporte, informando sua quantidade de atletas.
void consulta_esporte(lista_nodo *init, char esporte[]) {

}

    //remove um esporte da lista/ABP.
void remove_esporte(lista_nodo **init, char esporte[]) {

}


    /*
     *  ATLETA
     */

    //permite a inserção de um atleta em um esporte.
void insere_atleta(lista_nodo *init, char nome_esporte[], char nome_atleta[]) {
    lista_nodo *esporte = busca_esporte(init, nome_esporte);
    if(esporte == NULL) {
        return;
    }
    
    arvore_nodo *atleta = (arvore_nodo*) malloc(sizeof(arvore_nodo));
    strcpy(atleta->nome, nome_atleta);
    atleta->dir = NULL;
    atleta->esq = NULL;

    if(esporte->atleta == NULL) {
        esporte->atleta = atleta;
        return;
    }
    
    arvore_nodo *aux = esporte->atleta;
    while(aux != NULL) {
        if(strcmp(atleta->nome, aux->nome) < 0) {
            if(aux->esq == NULL) {
                aux->esq = atleta;
                return;
            }
            aux = aux->esq;
            continue;
        }
        if(strcmp(atleta->nome, aux->nome) > 0) {
            if(aux->dir == NULL) {
                aux->dir = atleta;
                return;
            }
            aux = aux->dir;
            continue;
        }

        printf("\nEsse esporte ja contem esse atleta!\n");
        return;
    }
}

    //retorna o número total de atletas.
void total_atletas(lista_nodo *init) {

}

    //retorna o total de atletas em cada esporte, em ordem decrescente de total de atletas.
void total_atletas_ordenado(lista_nodo *init) {

}

    //exibe a lista dos nomes de todos os atletas em ordem alfabética (de A a Z) ou em ordem alfabética inversa (de Z a A).
void exibe_atletas_total(lista_nodo *init) {

}


void exibe_atletas_esporte_loop(arvore_nodo *nodo) {
    if(nodo == NULL) {
        return;
    }
    exibe_atletas_esporte_loop(nodo->esq);
    printf("%s - ", nodo->nome);
    exibe_atletas_esporte_loop(nodo->dir);
}
    //exibe a lista dos nomes dos atletas de um esporte, em ordem alfabética (de A a Z) ou em ordem alfabética inversa (de Z a A).
void exibe_atletas_esporte(lista_nodo *init, char nome_esporte[]) {
    lista_nodo *esporte = busca_esporte(init, nome_esporte);
    if(esporte == NULL) {
        return;
    }
    if(esporte->atleta == NULL) {
        printf("\nEsse esporte nao possui nenhum atleta!\n");
    }
    
    printf("\nLista: ");
    exibe_atletas_esporte_loop(esporte->atleta);
    printf("\n");
}

    //exibe os nomes dos atletas de um esporte em ordem pré-fixada.
void percurso_prefixado (lista_nodo *init, char esporte[]) {
    
}

    //remove um atleta de um esporte específico.
void remove_atleta(lista_nodo *init, char esporte[], char atleta[]) {

}

int main() {
    printf("\n\nInicializando Sistema!!!\n\n");

    lista_nodo *esportes = NULL;

    int acao = 0;
    while(1) {
        printf("\nOperações:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Esporte\n");
        printf("2 - Listar Esportes\n");
        printf("3 - Consultar Esporte\n");
        printf("4 - Remover Esporte\n");
        printf("6 - Inserir Atleta\n");
        printf("7 - Total Atletas\n");
        printf("8 - Total Atletas Ordenado\n");
        printf("9 - Exibe Atletas Total\n");
        printf("10 - Exibe Atletas Esporte\n");
        printf("11 - Percurso Prefixado\n");
        printf("12 - Remover Atleta\n");
        printf("Acao: ");
        scanf("%d", &acao);

        char nome_esporte[50], nome_atleta[50];
        switch(acao) {
            case 0:
                printf("\n\nFinalizando sistema!!!\n\n");
                return 0;
            case 1:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                insere_esporte(&esportes, nome_esporte);
                break;
            case 2:
                listar_esportes(esportes);
                break;
            case 3:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                consulta_esporte(esportes, nome_esporte);
                break;
            case 4:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                remove_esporte(&esportes, nome_esporte);
                break;

            case 6:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                printf("Nome do Atleta: ");
                scanf("%s", nome_atleta);
                insere_atleta(esportes, nome_esporte, nome_atleta);
                break;
            case 7:
                total_atletas(esportes);
                break;
            case 8:
                total_atletas_ordenado(esportes);
                break;
            case 9:
                exibe_atletas_total(esportes);
                break;
            case 10:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                exibe_atletas_esporte(esportes, nome_esporte);
                break;
            case 11:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                percurso_prefixado(esportes, nome_esporte);
                break;
            case 12:
                printf("\nNome do Esporte: ");
                scanf("%s", nome_esporte);
                printf("Nome do Atleta: ");
                scanf("%s", nome_atleta);
                remove_atleta(esportes, nome_esporte, nome_atleta);
                break;
        }
    }

    printf("\n\nFinalizando sistema!!!\n\n");
}
