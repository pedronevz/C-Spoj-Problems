#include <stdio.h> 

int binarySearch(int *array, int n, int query) {
    int esquerda = 0, direita = n - 1, resultado = -1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (array[meio] == query) {
            resultado = meio;
            direita = meio - 1; // Continue buscando à esquerda para encontrar a primeira ocorrência
        } else if (array[meio] < query) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return resultado;
}


int main() {
    int n;
    int q;

    scanf("%d %d", &n, &q);
    
    int vetorElementos[n];

    for (int i = 0; i < n; i++) { 
        scanf("%d", &vetorElementos[i]);
    }

    int arrayPosicoes[q];

    for (int i = 0; i < q; i++) { 
        int query;
        scanf("%d", &query);
        arrayPosicoes[i] = binarySearch(vetorElementos, n, query);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", arrayPosicoes[i]);
    }

    return 0;
}