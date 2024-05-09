#include <stdio.h>
#include <stdlib.h>

/* Função para trocar dois elementos de posição no array */
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Função para encontrar o pivô e particionar o array */
int partition(int array[], int low, int high) 
{
    int pivot = array[high]; /* O pivô é o último elemento */
    int i = (low - 1); /* O índice do menor elemento */
    int j = 0;

    for (j = low; j <= high - 1; j++) 
    {
        /* Se o elemento atual for menor ou igual ao pivô */
        if (array[j] <= pivot) 
        {
            i++; /* Incrementa o índice do menor elemento */
            swap(&array[i], &array[j]); /* Troca os elementos */
        }
    }
    swap(&array[i + 1], &array[high]); /* Coloca o pivô no lugar certo */
    return (i + 1); /* Retorna a posição do pivô */
}

/* Função principal do Quicksort */

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        /* Encontra o pivô e particiona o array */ 
        int pi = partition(array, low, high);

        /* Ordena os elementos antes e depois do pivô recursivamente */
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
} 