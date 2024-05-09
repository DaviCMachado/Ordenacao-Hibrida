#include <stdio.h>
#include <stdlib.h>

void merge (int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Cria vetores temporários */
    int L[n1], R[n2];

    /* Copia os dados para os vetores temporários L[] e R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Junta os vetores temporários de volta ao vetor original arr[left..right] */
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

    /* Copia os elementos restantes de L[], se houver */
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copia os elementos restantes de R[], se houver */
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
        /* Calcula o meio do vetor */
        int mid = left + (right - left) / 2;

        /* Ordena a metade esquerda */
        mergeSort(arr, left, mid);
        /* Ordena a metade direita */
        mergeSort(arr, mid + 1, right);

        /* Une as partes ordenadas*/
        merge(arr, left, mid, right);
    }
}

void insertionSort(int arr[], int left, int right) {
    
    int key = 0;
    int j = 0;
    int i = 0;

    for (i = left + 1; i <= right; i++) 
    {
        key = arr[i];
        j = i - 1;
        
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }       
        arr[j + 1] = key;
    }
}

void timSort(int arr[], int left, int right, int threshold) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (right - left + 1 <= threshold) 
        {
            insertionSort(arr, left, right);
        } 
        else 
        {
            timSort(arr, left, mid, threshold);
            timSort(arr, mid + 1, right, threshold);
            merge(arr, left, mid, right);
        }
    }
}

void algor1 (int numeros[], int inicio, int high) 
{
    int threshold = 10;
    timSort(numeros, inicio, high, threshold);
}



