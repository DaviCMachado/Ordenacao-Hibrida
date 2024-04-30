#include "algoritmo1.c"
#include "algoritmo2.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Funcao de execucao dos algoritmos */
void testa_algoritmo (void (*funcao)(), int numeros_teste[], int contador, int n)
{

    printf("\n\nExecutando algoritmo %d...\n", n);
    clock_t inicio = clock();

    /* Ordena os numeros usando a funcao dada */
    funcao(numeros_teste, 0, contador - 1);

    clock_t fim = clock();

    /* Calcula o tempo de execucao em segundos */
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
       
    /* Testa se o input eh valido */
    int i = 0;
    if (scanf("%d", &printar) == 1) 
    {
        if (printar == 1) 
        {
            printf("Numeros ordenados:\n");
            for (i = 0; i < contador; i++) 
                printf("%d ", numeros_teste[i]);
            
            printf("\n");
        }
    } 
    else 
    {
        /* Limpa o input buffer */
        while (getchar() != '\n');
    } 
}

int main (int argc, char *argv[]) 
{
    /* Checa se o nome do arquivo foi dado como um argumento de linha de comando */
    if (argc != 2) 
    {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    /* Abrir o arquivo para leitura */
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) 
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    int capacidade = 10; /* capacidade inicial dos arrays */

    /* Criacao dos arrays para receber os numeros */
    int *numeros_MergeSort = malloc(capacidade * sizeof(int));
    int *numeros_QuickSort = malloc(capacidade * sizeof(int));
    int *numeros_algor1 = malloc(capacidade * sizeof(int));
    int *numeros_algor2 = malloc(capacidade * sizeof(int));
    
    if (numeros_algor1 == NULL || numeros_algor2 == NULL || numeros_MergeSort == NULL || numeros_QuickSort == NULL) 
    {
        perror("Erro de alocacao de memoria");
        fclose(arquivo);
        free(numeros_algor1);
        free(numeros_algor2);
        free(numeros_MergeSort);
        free(numeros_QuickSort);
        return 1;
    }

    /* Leitura dos numeros do arquivo */
    int nr = 0;
    int contador = 0;

    while (fscanf(arquivo, "%d", &nr) == 1) 
    { 
        numeros_MergeSort[contador] = nr;
        numeros_QuickSort[contador] = nr;  
        numeros_algor1[contador] = nr;
        numeros_algor2[contador] = nr;        

        if (contador >= (capacidade - 1) ) 
        {
            capacidade *= 2; /* Duplica a capacidade do array quando necessário */

            numeros_algor1 = realloc(numeros_algor1, capacidade * sizeof(int));
            numeros_algor2 = realloc(numeros_algor2, capacidade * sizeof(int));
            numeros_MergeSort = realloc(numeros_MergeSort, capacidade * sizeof(int));
            numeros_QuickSort = realloc(numeros_QuickSort, capacidade * sizeof(int));
            
            if (numeros_algor1 == NULL || numeros_algor2 == NULL || numeros_MergeSort == NULL || numeros_QuickSort == NULL) 
            {
                perror("Erro de alocação de memória");
                fclose(arquivo);
                free(numeros_algor1);
                free(numeros_algor2);
                free(numeros_MergeSort);
                free(numeros_QuickSort);
                return 1;
            }
        }
        numeros_algor1[contador] = nr;
        numeros_algor2[contador] = nr;
        numeros_MergeSort[contador] = nr;
        numeros_QuickSort[contador] = nr;
        contador++;
    } 

    /* Fechar o arquivo */
    fclose(arquivo);

    contador--; /* Decrementa o contador para o tamanho correto do array */

    testa_algoritmo(mergeSort, numeros_MergeSort, contador, 1);
    testa_algoritmo(algor1, numeros_algor1, contador, 2);
    /* testa_algoritmo(quickSort, numeros_QuickSort, contador, 3);*/
    /* testa_algoritmo(algor2, numeros_algor2, contador, 4);*/

    /* Liberar a memória alocada */
    free(numeros_algor1);
    free(numeros_algor2);

    return 0;
}
