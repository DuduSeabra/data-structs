#include <stdio.h>
#include <stdlib.h>

void inicializar(int **grafo, int n_nos, int n_arestas) {
    for(int i = 0; i < n_nos; i++)
        grafo[i] = (int *) malloc(n_arestas * sizeof(int));
}

void inserir(int **grafo, int n_arestas, int n_instancia) {
    int v1, v2;

    if(n_instancia == 0) {
        for(int i = 0;i < n_arestas;i++) {
            //printf("Digite os grafos conectados: ");
            scanf("%d %d", &v1, &v2);
            if(v1 == v2) {
                grafo[v1-1][i] = 1;
            }
            else {
                grafo[v1-1][i] = 1;
                grafo[v2-1][i] = 1;
            }
        }
    }
    else {
        printf("Instância não reconhecida.\n");
    }
}

int imprimir_grau(int **grafo, int n_nos, int n_arestas) {
    int count = 0, max = 0, min = 100, aux = 0, aux1, aux2, aux3 = 1;

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_arestas; j++) {
            if(grafo[i][j] == 1)
                count++;
        }
        for(int x = 0; x < n_arestas; x++) {
            for(int y = 0; y < n_nos; y++) {
                if(grafo[y][x] == 1) {
                    aux++;
                    aux1 = y;
                }
            }
            if(aux == 1 && i == aux1)
                count++;
            aux = 0;
        }
        if(i == 0)
            aux2 = count;
        if(aux2 != count)
            aux3 = 0;
        printf("Vértice %d tem grau %d\n", i+1, count);
        if(count > max)
            max = count;
        if(count < min)
            min = count;
        count = 0;
    }
    printf("\n");
    printf("Grau máximo: %d\n", max);
    printf("Grau mínimo: %d\n", min);

    return aux3;
}

void imprimir_grafo(int **grafo, int n_nos, int n_arestas) {

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_arestas; j++) {
            if(j == 0)
                printf("%d", grafo[i][j]);
            else
                printf(" %d", grafo[i][j]);
        }
        printf("\n");
    }
}

void loop(int **grafo, int n_nos, int n_arestas) {
    int count = 0, aux1 = 0, aux2;

    for(int j = 0; j < n_arestas; j++) {
        for(int i = 0; i < n_nos; i++) {
            if(grafo[i][j] == 1) {
                aux1++;
                aux2 = i;
            }
        }
        if(aux1 == 1) {
            count++;
            if(count == 1) {
                printf("Há loop nos vértices abaixo:\n%d", aux2+1);
            }
            else
                printf(" %d", aux2+1);
        }
        aux1 = 0;
    }
    if(count != 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
    else
        printf("Não há loops\n");
}

void arestas_paralelas(int **grafo, int n_nos, int n_arestas) {
    int count = 0, aux;
    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_arestas-1; j++) {
            if(grafo[i][j] == 1 && grafo[i][j+1] == 1) {
                aux = i+1;
                while(aux < n_nos) {
                    if(grafo[aux][j] == 1 && grafo[aux][j+1] == 1) {
                        count = count + 2;
                        if(count == 2) {
                            printf("Entre os vértices abaixo há arestas paralelas:\n%d %d", i+1, aux+1);
                        }
                        else
                            printf(" %d %d", i+1, aux+1);
                    }
                    aux++;
                }
            }
        }
    }
    if(count != 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
    else
        printf("Não há arestas paralelas\n");
}

void vertices_isolados(int **grafo, int n_nos, int n_arestas) {
    int count = 0;

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_arestas; j++) {
            if(grafo[i][j] == 1) {
                break;
            }
            if(grafo[i][j] == 0 && j+1 == n_arestas) {
                count++;
                if(count == 1) {
                    printf("Os vértices abaixo são isolados:\n%d", i+1);
                }
                else
                    printf(" %d", i+1);
            }
        }
    }
    if(count != 0) {
        printf("\n");
        printf("Total: %d\n", count);
    }
    else
        printf("Não há vertices isolados\n");
}

void grafo_completo(int **grafo, int n_nos, int n_arestas) {
    int aux = 1, aux1 = 1, aux2 = 0;

    while(aux2 < n_arestas) {
        while(aux < n_nos) {
            if(grafo[aux][aux2] != 1) {
                printf("Grafo não completo\n");
                return;
            }
            aux++;
            aux2++;
        }
        aux1++;
        aux = aux1;
    }
    printf("Grafo Completo\n");
}

void grafo_regular(int **grafo, int n_nos, int n_arestas) {
    int count = 0, aux = 0, aux1, aux2, aux3 = 1;

    for(int i = 0; i < n_nos; i++) {
        for(int j = 0; j < n_arestas; j++) {
            if(grafo[i][j] == 1)
                count++;
        }
        for(int x = 0; x < n_arestas; x++) {
            for(int y = 0; y < n_nos; y++) {
                if(grafo[y][x] == 1) {
                    aux++;
                    aux1 = y;
                }
            }
            if(aux == 1 && i == aux1)
                count++;
            aux = 0;
        }
        if(i == 0)
            aux2 = count;
        if(aux2 != count)
            aux3 = 0;
        count = 0;
    }

    if(aux3 == 1)
        printf("Grafo regular\n");
    else
        printf("Grafo não regular\n");
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

    int **grafo = (int **)malloc((n_nos+1) * sizeof(int *));

    inicializar(grafo, n_nos, n_arestas);

    inserir(grafo, n_arestas, n_instancia);

    scanf(" %[^\n]*c", v);
    
    for(int i = 0; v[i] != '0'; i += 2) {
        v1[aux] = v[i] - '0';
        aux++;
    }

    for(int i = 0; v1[i] != 0; i++)
        len++;

    imprimir_grafo(grafo, n_nos, n_arestas);
    printf("\n");
    loop(grafo, n_nos, n_arestas);
    printf("\n");
    arestas_paralelas(grafo, n_nos, n_arestas);
    printf("\n");
    vertices_isolados(grafo, n_nos, n_arestas);
    printf("\n");
    imprimir_grau(grafo, n_nos, n_arestas);
    printf("\n");
    grafo_completo(grafo, n_nos, n_arestas);
    grafo_regular(grafo, n_nos, n_arestas);
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