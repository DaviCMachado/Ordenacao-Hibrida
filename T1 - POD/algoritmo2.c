#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void findMinMax(int arr[], int n, int *min, int *max) 
{
    *min = *max = arr[0];
    int i;
    for ( i = 1; i < n; i++) 
    {
        if (arr[i] < *min) 
            *min = arr[i];
        else if 
            (arr[i] > *max) *max = arr[i];
    }
}


void spreadSort (int arr[], int n) 
{
    int min, max, i;
    findMinMax(arr, n, &min, &max);
    uint32_t *buckets = calloc(max - min + 1, sizeof(uint32_t));

    for (i = 0; i < n; i++)
        buckets[arr[i] - min]++;

    int idx = 0;
    for (i = min; i <= max; i++) 
    {
        while (buckets[i - min] > 0) 
        {
            arr[idx++] = i;
            buckets[i - min]--;
        }
    }

    /*Agora, eh preciso corrigir o ultimo elemento que nao esta ordenado*/

    int j = 0;
    int ultimo = arr[n];
    int temp;
    while (arr[j] < ultimo)
        j++;
    
    for (i = n; i > j; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[j] = ultimo;

    /*Todo array agora esta ordenado*/

    free(buckets);
}


void Spread (int numeros[], int low, int high) 
{
    spreadSort(numeros + low, high);
}








