#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função merge (para uso interno, mesmo que não precise ordenar o resultado)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    char linha1[10], linha2[200];
    fgets(linha1, sizeof(linha1), stdin);
    int n = atoi(linha1);

    fgets(linha2, sizeof(linha2), stdin);

    int p[101], resultado[101];
    char *token = strtok(linha2, " \n");
    int i = 0;

    while (token != NULL && i < n) {
        p[i++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    // Inverter a relação: quem deu presente para quem
    for (int j = 0; j < n; j++) {
        int destinatario = p[j];
        resultado[destinatario - 1] = j + 1;
    }

    // Opcional: mergeSort(resultado, 0, n - 1);  <-- NÃO USAR, pois altera a ordem lógica!

    for (int j = 0; j < n; j++) {
        printf("%d ", resultado[j]);
    }

    printf("\n");
    return 0;
}
