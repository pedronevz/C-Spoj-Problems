#include <stdio.h>

void merge(int *Vetor, int inicio, int meio, int fim, int *temp) {
    int i0 = inicio, i1 = meio + 1, iTemp = inicio;

    // Combina os dois subvetores ordenados
    while (i0 <= meio && i1 <= fim) {
        if (Vetor[i0] <= Vetor[i1]) {
            temp[iTemp++] = Vetor[i0++];
        } else {
            temp[iTemp++] = Vetor[i1++];
        }
    }

    // Copia o restante do subvetor esquerdo (se houver)
    while (i0 <= meio) {
        temp[iTemp++] = Vetor[i0++];
    }

    // Copia o restante do subvetor direito (se houver)
    while (i1 <= fim) {
        temp[iTemp++] = Vetor[i1++];
    }

    // Copia de volta para o vetor original
    for (iTemp = inicio; iTemp <= fim; iTemp++) {
        Vetor[iTemp] = temp[iTemp];
    }
}

void mergeSort(int *Vetor, int inicio, int fim, int *temp) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(Vetor, inicio, meio, temp);
        mergeSort(Vetor, meio + 1, fim, temp);
        merge(Vetor, inicio, meio, fim, temp);
    }
}

int main() {
    int vetor[100000]; // Vetor com tamanho máximo de 100000 elementos
    int temp[100000];  // Vetor auxiliar para o merge sort
    int tamanho = 0;
    int i;

    while (scanf("%d", &vetor[tamanho]) == 1) {
        tamanho++;
        if (getchar() == '\n') break; // Termina ao encontrar o Enter
    }

    mergeSort(vetor, 0, tamanho - 1, temp);

    for (i = 0; i < tamanho; i++) {
        if (i > 0) printf(" ");
        printf("%d", vetor[i]);
    }
    printf("\n");

    return 0;
}