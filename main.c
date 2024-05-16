#include "algoritmo1.c"
#include "algoritmo2.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Funcao de execucao dos algoritmos */
void testa_algoritmo (void (*funcao)(), int numeros_teste[], int contador, int n)
{
    char str[30];
    switch (n)
    {
        case 1:
            strcpy(str,"TimSort");
            break;
        case 2:
            strcpy(str,"QuickSort");
            break;
        case 3:
            strcpy(str,"KirkPatrick-Reisch_Sort");
            break;
        case 4:
            strcpy(str,"SpreadSort");
            break;
        default:
            exit(1);
    }

    printf("\n\nExecutando Algoritmo %s ...\n", str);
    clock_t inicio = clock();

    /* Ordena os numeros usando a funcao dada */
    funcao(numeros_teste, 0, contador);

    clock_t fim = clock();

    /* Calcula o tempo de execucao em segundos */
    float tempo_execucao = ((float) fim - (float) inicio) / CLOCKS_PER_SEC;

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
            printf("\nNumeros ordenados:\n");
            for (i = 0; i <= contador; i++) 
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
    int *numeros_TimSort = malloc(capacidade * sizeof(int));
    int *numeros_QuickSort = malloc(capacidade * sizeof(int));
    int *numeros_Kirk = malloc(capacidade * sizeof(int));
    int *numeros_SpreadSort = malloc(capacidade * sizeof(int));
    
    if (numeros_Kirk == NULL || numeros_SpreadSort == NULL || numeros_TimSort == NULL || numeros_QuickSort == NULL) 
    {
        perror("Erro de alocacao de memoria");
        fclose(arquivo);
        free(numeros_Kirk);
        free(numeros_SpreadSort);
        free(numeros_TimSort);
        free(numeros_QuickSort);
        return 1;
    }

    /* Leitura dos numeros do arquivo */
    int nr = 0;
    int contador = 0;
    
    printf("\nLeitura do arquivo em andamento...\n");

    while (fscanf(arquivo, "%d", &nr) == 1) 
    { 
        numeros_TimSort[contador] = nr;
        numeros_QuickSort[contador] = nr;  
        numeros_Kirk[contador] = nr;
        numeros_SpreadSort[contador] = nr;        

        if (contador >= (capacidade - 1) ) 
        {
            capacidade *= 2; /* Duplica a capacidade do array quando necessário */

            numeros_Kirk = realloc(numeros_Kirk, capacidade * sizeof(int));
            numeros_SpreadSort = realloc(numeros_SpreadSort, capacidade * sizeof(int));
            numeros_TimSort = realloc(numeros_TimSort, capacidade * sizeof(int));
            numeros_QuickSort = realloc(numeros_QuickSort, capacidade * sizeof(int));
            
            if (numeros_Kirk == NULL || numeros_SpreadSort == NULL || numeros_TimSort == NULL || numeros_QuickSort == NULL) 
            {
                perror("Erro de alocação de memória");
                fclose(arquivo);
                free(numeros_Kirk);
                free(numeros_SpreadSort);
                free(numeros_TimSort);
                free(numeros_QuickSort);
                return 1;
            }
        }
        numeros_Kirk[contador] = nr;
        numeros_SpreadSort[contador] = nr;
        numeros_TimSort[contador] = nr;
        numeros_QuickSort[contador] = nr;
        contador++;
    } 

    /* Fechar o arquivo */
    fclose(arquivo); 

    printf("\nLeitura concluida com sucesso!\n");
    printf("\n%d numeros inteiros lidos\n", contador);

    contador--; /* Decrementa o contador para o tamanho correto do array */

    testa_algoritmo(Tim, numeros_TimSort, contador, 1); 
    testa_algoritmo(quickSort, numeros_QuickSort, contador, 3);
    testa_algoritmo(Kirk, numeros_Kirk, contador, 2);
    testa_algoritmo(Spread, numeros_SpreadSort, contador, 4);

    /* Liberar a memória alocada */
    free(numeros_Kirk);
    free(numeros_SpreadSort);
    free(numeros_TimSort);
    free(numeros_QuickSort);

    return 0;
}
