#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct lista_nodo {
    char nome[50];
    struct lista_nodo *prox;
} lista_nodo;

typedef struct arvore_nodo {
    char nome[50];
    struct arvore_nodo *esq, *dir;
} arvore_nodo;



/*
 *  ESPORTES
 */
    //permite a inserção de um esporte.
void insere_esporte(lista_nodo **init, char esporte[]) {

}

    //retorna um esporte pelo nome.
lista_nodo* busca_esporte(lista_nodo *init, char esporte[]) {
    return NULL;
}

    //escreve todos os esportes.
void listar_esportes(lista_nodo *init) {

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
void insere_atleta(lista_nodo *init, char esporte[], char atleta[]) {

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

    //exibe a lista dos nomes dos atletas de um esporte, em ordem alfabética (de A a Z) ou em ordem alfabética inversa (de Z a A).
void exibe_atletas_esporte(lista_nodo *init, char esporte[]) {

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
