#ifndef ALGORITMO1_H
#define ALGORITMO1_H

/* chamadas de funcoes do algoritmo 1 */

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);  
void insertionSort(int arr[], int left, int right);
void hybridSort(int arr[], int left, int right, int threshold);
void algor1(int numeros[], int inicio, int size); /* funcao principal do primeiro algoritmo */

#endif