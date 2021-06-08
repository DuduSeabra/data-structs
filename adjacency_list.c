#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor_no;
    struct lista *prox;
} LISTA;

void inicializar(LISTA *grafo, int n_nos) {
    for(int i = 0; i < n_nos; i++) {
        grafo[i].valor_no = i+1;
        grafo[i].prox = NULL;
    }
}

void inserir(LISTA *grafo, int n_arestas, int n_instancia) {
    int v1, v2;
    LISTA *aux;

    if(n_instancia == 0) {
        for(int i = 0; i < n_arestas; i++) {
            //printf("Digite os grafos conectados: ");
            scanf("%d%d", &v1, &v2);
            aux = &grafo[v1-1];

            if(v1 != v2) {
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                LISTA *new_node1 = (LISTA *) malloc(sizeof(LISTA));
                aux->prox = new_node1;
                new_node1->valor_no = v2-1;
                new_node1->prox = NULL;

                aux = &grafo[v2-1];
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                LISTA *new_node2 = (LISTA *) malloc(sizeof(LISTA));
                aux->prox = new_node2;
                new_node2->valor_no = v1-1;
                new_node2->prox = NULL;
            }
            else {
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                LISTA *new_node1 = (LISTA *) malloc(sizeof(LISTA));
                aux->prox = new_node1;
                new_node1->valor_no = v2-1;
                new_node1->prox = NULL;
            }
        }
    }
}

void imprimir_grafo(LISTA *grafo, int n_nos) {
    LISTA *aux;

    for(int i = 0; i < n_nos; i++) {
        printf("%d:", i+1);
        aux = grafo[i].prox;
        while(aux != NULL) {
            printf(" %d", (aux->valor_no)+1);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void imprimir_grau(LISTA *grafo, int n_nos) {
    int count = 0;
    int max = 0,min = 100;

    LISTA *aux;

    for(int i = 0; i < n_nos; i++) {
        aux = &grafo[i];

        printf("Vértice %d tem grau ", i+1);
        while(aux->prox != NULL) {
            aux = aux->prox;
            if(aux->valor_no == i)
                count = count + 2;
            else
                count++;
        }
        printf("%d\n", count);
        if(count > max)
            max = count;
        if(count < min)
            min = count;
        count = 0;
    }
    printf("\n");
    printf("Grau máximo: %d\n", max);
    printf("Grau mínimo: %d\n", min);
}

void loop(LISTA *grafo, int n_nos) {
    int count = 0;
    LISTA *aux;

    for(int i = 0; i < n_nos; i++) {
        aux = grafo[i].prox;

        while(aux != NULL) {
            if(aux->valor_no == i) {
                count++;
                if(count == 1) {
                    printf("Há loop nos vértices abaixo:\n%d", i+1);
                }
                else {
                    printf(" %d", i+1);
                }
                break;
            }
            aux = aux->prox;
        }
    }
    if(count > 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
    else {
        printf("Não há loops\n");
    }
}

void aresta_paralela(LISTA *grafo, int n_nos) {
    int aux1, aux2;
    LISTA *aux;
    int count = 0;

    for(int i = 0; i < n_nos; i++) {
        aux = grafo[i].prox;

        while(aux != NULL) {
            if(aux->prox == NULL)
                break;
            aux1 = aux->valor_no;
            aux2 = aux->prox->valor_no;
            
            if(aux1 == aux2) {
                printf("Entre os vértices abaixo há arestas paralelas:\n%d %d\n", i+1, aux1+1);
                count = count + 2;
                break;
            }
            aux = aux->prox;
        }
        if(aux1 == aux2)
            break;
    }
    if(count > 0)
        printf("Total: %d\n", count);
    else {
        printf("Não há arestas paralelas\n");
    }
}

void vertice_isolado(LISTA *grafo, int n_nos) {
    int count = 0;

    for(int i = 0; i < n_nos; i++) {
        if(grafo[i].prox == NULL) {
            count++;
            if(count == 1) {
                printf("Os vértices abaixo são isolados:\n%d", i+1);
            }
            else {
                printf(" %d", i+1);
            }
        }
    }
    if(count > 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
    else {
        printf("Não há vertices isolados\n");
    }
}

void grafo_completo(LISTA *grafo, int n_nos) {
    int count = 0;
    LISTA *aux;

    for(int i = 0; i < n_nos; i++) {
        aux = grafo[i].prox;
        while(aux != NULL) {
            if(aux->prox != NULL) {
                if(aux->valor_no == aux->prox->valor_no) {
                    printf("Grafo não completo\n");
                    return;
                }
            }
            count++;
            aux = aux->prox;
        }
        if(count != n_nos-1) {
            printf("Grafo não completo\n");
            return;
        }
        count = 0;
    }
    printf("Grafo Completo\n");
}

void grafo_regular(LISTA *grafo, int n_nos) {
    int count = 0;
    int aux1 = 0;

    LISTA *aux;

    for(int i = 0; i < n_nos; i++) {
        aux = &grafo[i];

        while(aux->prox != NULL) {
            aux = aux->prox;
            if(aux->valor_no == i)
                count = count + 2;
            else
                count++;
        }
        if(i == 0)
            aux1 = count;
        if(aux1 != count) {
            printf("Grafo não regular\n");
            return;
        }
        aux1 = count;
        count = 0;
    }
    printf("Grafo regular\n");
}

void caminho_elementar(int *v, int len) {
    int count = 0, aux, aux1 = 0;

    for(int i = 0; i < len; i++) {
        aux = v[i];
        while(aux1 < len) {
            if(aux == v[aux1])
                count++;
            aux1++;
        }
        aux1 = 0;
        if(count > 1) {
            printf("O caminho não é elementar\n");
            return;
        }
        count = 0;
    }
    printf("O caminho é elementar\n");
}

void caminho_ciclo(int *v, int len) {
    if(v[0] == v[len-1])
        printf("O caminho é um ciclo\n");
    else
        printf("O caminho não é um ciclo\n");
}

void caminho_trajeto(int *v, int len) {
    int aux1, aux2, aux3 = 0;
    for(int i = 0; i < len-1; i++) {
        aux1 = i;
        aux2 = i+1;
        while(aux3 < len-1) {
            if((v[aux3] == v[aux2] && v[aux3+1] == v[aux1]) || (v[aux3] == v[aux1] && v[aux3+1] == v[aux2] && aux3 != aux1 && aux3+1 != aux2)) {
                printf("O caminho não é um trajeto\n");
                return;
            }
            aux3++;
        }
        aux3 = 0;
    }
    printf("O caminho é um trajeto\n");
}

int main() {

    int n_nos;
    int n_arestas;
    int n_instancia;
    int len = 0;
    char v[30];
    int *v1 = (int *) malloc(30 * sizeof(int));
    int aux = 0;

    for(int i = 0; i < 30; i++)
        v[i] = '0';
    
    //printf("Números de nós: ");
    scanf("%d", &n_nos);
    //printf("Números de vértices: ");
    scanf("%d", &n_arestas);
    //printf("Qual instância? (0-não orientado, 1-orientado, 2-não orientado e ponderado, 3-orientado e ponderado)\n");
    scanf("%d", &n_instancia);

    LISTA *grafo = (LISTA *) malloc((n_nos+1) * sizeof(LISTA));

    inicializar(grafo, n_nos);

    inserir(grafo, n_arestas, n_instancia);

    scanf(" %[^\n]*c", v);
    
    for(int i = 0; v[i] != '0'; i += 2) {
        v1[aux] = v[i] - '0';
        aux++;
    }
    for(int i = 0; v1[i] != 0; i++)
        len++;

    imprimir_grafo(grafo, n_nos);
    printf("\n");
    loop(grafo, n_nos);
    printf("\n");
    aresta_paralela(grafo, n_nos);
    printf("\n");
    vertice_isolado(grafo, n_nos);
    printf("\n");imprimir_grau(grafo, n_nos);
    printf("\n");
    grafo_completo(grafo, n_nos);
    grafo_regular(grafo, n_nos);
    printf("\n");
    caminho_elementar(v1, len);
    caminho_ciclo(v1, len);
    caminho_trajeto(v1, len);

    return 0;
}