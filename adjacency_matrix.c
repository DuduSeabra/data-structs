#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inicializar(int **grafo, int n_nos) {
    for(int i = 0;i < (n_nos+1);i++) {
        grafo[i] = (int *) malloc((n_nos+1) * sizeof(int));
        for(int j = 0;j < (n_nos+1);j++) {
            grafo[i][j] = 0;
        }
    }
}

void inserir(int **grafo, int n_arestas, int n_instancia) {
    int v1,v2;

    if(n_instancia == 0) {
        for(int i = 0;i < n_arestas;i++) {
            //printf("Digite os grafos conectados: ");
            scanf("%d%d", &v1, &v2);
            if(v1 == v2)
                grafo[v1-1][v2-1] = 2;
            else if(grafo[v1-1][v2-1] == 1 && grafo[v2-1][v1-1] == 1) {
                grafo[v1-1][v2-1] = 2;
                grafo[v2-1][v1-1] = 2;
            }
            else {
                grafo[v1-1][v2-1] = 1;
                grafo[v2-1][v1-1] = 1;
            }
        }
    }
    else {
        printf("Comando não reconhecido.\n");
    }
}

void imprimir_grau(int **grafo, int n_nos) {
    int max = 0, min = 100;
    int count = 0;

    for(int i = 0; i < n_nos; i++) {
        printf("Vértice %d tem grau ", i+1);
        for(int j = 0; j < n_nos; j++) {
            count = count + grafo[i][j];
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

void imprimir_grafo(int **grafo, int n_nos) {
    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_nos;j++) {
            printf("%d", grafo[i][j]);
            if(j+1 != n_nos)
                printf(" ");
        }
        printf("\n");
    }
}

void loop(int **grafo, int n_nos) {
    int count = 0;
    for(int i = 0; i < n_nos; i++) {
        if(grafo[i][i] == 2) {
            count++;
            if(count == 1)
                printf("Há loop nos vértices abaixo:\n%d", i+1);
            else
                printf(" %d", i+1);
        }
    }
    if(count > 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
        
    else
        printf("Não há loops\n");
}

void aresta_paralela(int **grafo, int n_nos) {
    int count = 0;
    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_nos; j++) {
            if(grafo[i][j] == 2 && grafo[j][i] == 2 && i < j) {
                count = count + 2;
                if(count == 2) {
                    printf("Entre os vértices abaixo há arestas paralelas:\n%d %d\n", i+1, j+1);
                }
                else
                    printf("%d %d\n", i+1, j+1);
            }
        }
    }
    if(count != 0)
        printf("Total: %d\n", count);
    else
        printf("Não há arestas paralelas\n");
}

void vertice_isolado(int **grafo, int n_nos) {
    int count = 0;

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_nos; j++) {
            if(grafo[i][j] != 0) {
                break;
            }
            if(j+1 == n_nos && grafo[i][j] == 0) {
                count++;
                if(count == 1) {
                    printf("Os vértices abaixo são isolados:\n%d", i+1);
                }
                else
                    printf(" %d", i+1);
            }
        }
    }
    if(count == 0) {
        printf("Não há vertices isolados\n");
    }
    else {
        printf("\n");
        printf("Total: %d\n", count);
    }
}

void grafo_completo(int **grafo, int n_nos) {
    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_nos; j++) {
            if(grafo[i][j] == 0 && i != j) {
                printf("Grafo não completo\n");
                return;
            }
        }
    }
    printf("Grafo Completo\n");
}

void grafo_regular(int **grafo, int n_nos) {
    int count = 0, aux;

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_nos; j++) {
            count = count + grafo[i][j];
        }
        if(i == 0)
            aux = count;
        else {
            if(aux != count) {
                printf("Grafo não regular\n");
                return;
            }
        }
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

    int **grafo = (int **) malloc((n_nos+1) * sizeof(int *));

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
    printf("\n");
    imprimir_grau(grafo, n_nos);
    printf("\n");
    grafo_completo(grafo, n_nos);
    grafo_regular(grafo, n_nos);
    printf("\n");
    caminho_elementar(v1, len);
    caminho_ciclo(v1, len);
    caminho_trajeto(v1, len);

    for(int i = 0; i < n_nos+1; i++) {
        int *grafo_atual = grafo[i];
        free(grafo_atual);
    }
    
    return 0;
}