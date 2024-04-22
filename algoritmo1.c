#include <stdio.h>
#include <stdlib.h>
#include "algoritmo1.h"

void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria vetores temporários
    int L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Junta os vetores temporários de volta ao vetor original arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        // Calcula o meio do vetor
        int mid = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSort(arr, left, mid);
        // Ordena a metade direita
        mergeSort(arr, mid + 1, right);

        // Junta as metades ordenadas
        merge(arr, left, mid, right);
    }
}

void algor1 (int numeros[], int inicio, int size) 
{
    mergeSort(numeros, inicio, size);
}
