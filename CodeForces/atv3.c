#include <stdio.h>
#include <stdlib.h>

// Função para o merge (junção ordenada)
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

// Função recursiva do merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int p[n];       // p[i] = amigo que recebeu presente do amigo i+1
    int result[n];  // result[i] = quem deu presente para o amigo i+1

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Inverter a relação
    for (int i = 0; i < n; i++) {
        int destinatario = p[i];          // amigo que recebeu presente
        result[destinatario - 1] = i + 1; // quem deu o presente
    }

    // Ordenar o vetor result (usando merge sort)
    mergeSort(result, 0, n - 1);

    // Imprimir resultado
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
