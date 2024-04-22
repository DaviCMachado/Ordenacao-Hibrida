#include "algoritmo1.c"
#include "algoritmo2.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void testa_algoritmo (void (*funcao)(), int numeros_teste[], int contador, int n)
{
      // Medir o tempo final
    clock_t inicio = clock();

    // Ordenar os números usando o mergeSort
    funcao(numeros_teste, 0, contador - 1);

    // Medir o tempo final
    clock_t fim = clock();

    // Calcular o tempo de execução em segundos
    float tempo_execucao = ((float) fim - (float) inicio) / CLOCKS_PER_SEC;

    char str[20];
    switch (n)
    {
        case 1:
            strcpy(str,"MergeSort");
            break;
        case 2:
            strcpy(str,"Hibrido1");
            break;
        case 3:
            strcpy(str,"QuickSort");
            break;
        case 4:
            strcpy(str,"Hibrido2");
            break;
        default:
            exit(1);
    }

    printf("\nAlgoritmo %s executado com sucesso!\n", str);

    printf("\nTempo de execucao do algoritmo %s: %.4f segundos\n", str, tempo_execucao);

    int printar = 0;
    printf("\nDeseja imprimir os numeros ordenados? \n1 - (Sim), 0 - (Nao) : ");
       
    // Testa se a entrada é válida
    if (scanf("%d", &printar) == 1) 
    {
        if (printar == 1) 
        {
            printf("Numeros ordenados:\n");
            for (int i = 0; i < contador; i++) 
                printf("%d ", numeros_teste[i]);
            
            printf("\n");
        }
    } 
    else 
    {
        // Limpa o buffer de entrada
        while (getchar() != '\n');
    } 
}

int main (int argc, char *argv[]) 
{
    // Verificar se o nome do arquivo foi fornecido como argumento de linha de comando
    if (argc != 2) 
    {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) 
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Contar quantos números existem no arquivo
    int contador = 0;
    int numero;
    while (fscanf(arquivo, "%d", &numero) == 1) 
        contador++;

    // Voltar para o início do arquivo
    rewind(arquivo);

    // Criar os arrays para armazenar os números
    int *numeros_MergeSort = malloc(sizeof(int) * contador);
    int *numeros_QuickSort = malloc(sizeof(int) * contador);
    int *numeros_algor1 = malloc(sizeof(int) * contador);
    int *numeros_algor2 = malloc(sizeof(int) * contador);
    
    if (numeros_algor1 == NULL || numeros_algor2 == NULL) 
    {
        perror("Erro de alocação de memória");
        fclose(arquivo);
        return 1;
    }

    // Lê os números do arquivo e armazena-os nos arrays
    int nr = 0;
    for (int i = 0; i < contador; i++)
    {
        fscanf(arquivo, "%d", &nr);
        numeros_MergeSort[i] = nr;
        numeros_QuickSort[i] = nr;  
        numeros_algor1[i] = nr;
        numeros_algor2[i] = nr;
    } 

    // Fechar o arquivo
    fclose(arquivo);

    testa_algoritmo(mergeSort, numeros_MergeSort, contador, 1);
    testa_algoritmo(algor1, numeros_algor1, contador, 2);
    testa_algoritmo(quickSort, numeros_QuickSort, contador, 3);
    testa_algoritmo(algor2, numeros_algor2, contador, 4);

    // Liberar a memória alocada para os arrays
    free(numeros_algor1);
    free(numeros_algor2);

    return 0;
}
