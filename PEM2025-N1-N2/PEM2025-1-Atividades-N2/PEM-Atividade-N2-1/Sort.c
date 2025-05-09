/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: bubblesorte e insetion           *
 * Data - 09/05/2025                                      *
 * Autor: Elias Cesario da Cunha                          *
 *--------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bubble sort recebendo o endereço do verto em int *a , e o tamanho do verto em int n
void bubbleSort(int *a, int n) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                int temp = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

// insertion tambem tem a assinatura do metodo semelhante a do bubble sort com endereço do vertor  em *a , e tamanho em n
void insertion(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int chave = *(a + i);
        int j = i - 1;
        while (j >= 0 && *(a + j) > chave) {
            *(a + j + 1) = *(a + j);
            j--;
        }
        *(a + j + 1) = chave;
    }
}

int main() {
    // por falta de boolean inicio o programa 1 para começar o loop
    int programa = 1;

    while (programa) {
        // solicita ao usuario a ordenação de numeros N dado pelo o usuario na opção 1 
        // ou ver a diferença de velocidas entres os dois sort de na opção 2 
        printf("Deseja testar a velocidade do Bubble Sort e Insertion Sort (1) ou apenas ordenar N numeros (2)? ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int total;
                // solicita o tamanho dos numero para ver como eles se comportam em vetores diferentes
                // em numero pequenos a diferença é imperceptivel ja em numeros maior fica mais claro por isso a sugestao de acima de 10000
                printf("informe um numero de preferencia maior que 10000 : ");
                scanf("%d", &total);
                
                
                // faz 3 vetores para poder testar o tempo de ordençao 
                int numeros[total], bobblesort[total], insertionsort[total];

                for (int i = 0; i < total; i++) {
                    // popular o primeiro vetor usando a funcao rand() %
                    numeros[i] = rand() % total;
                }

                // Copiando os mesmos dados para ambos os vetores
                for (int i = 0; i < total; i++) {
                    // copia os valores de numeros[] para os outros dois vetores;
                    bobblesort[i] = numeros[i];
                    insertionsort[i] = numeros[i];
                }
                
                // usa o clock_t para inicar o "timer" e finalizar 
                clock_t iniciob = clock();
                bubbleSort(bobblesort, total);
                clock_t fimb = clock();
                // calcular o tempo em segundos ;
                double tempobubble = ((double)(fimb - iniciob)) / CLOCKS_PER_SEC;
                
                // repete o mesmo processo so que para o proximo sort
                clock_t inicioin = clock();
                insertion(insertionsort, total);
                clock_t fimin = clock();
                double tempoinsert = ((double)(fimin - inicioin)) / CLOCKS_PER_SEC;
                
                // faz o print dos dois sorte com %.6 para ficar mais precisa a diferenças
                printf("Tempo Bubble Sort: %.6f segundos\n", tempobubble);
                printf("Tempo Insertion Sort: %.6f segundos\n", tempoinsert);
                break;
            }

            case 2: {
                // solicita o total de numeros para ordenar
                int total;
                printf("qual o total de numeros para ordenar? ");
                scanf("%d", &total);
                
                // criar o vetor depois que o usuario informa o numero total
                int numeros[total];

                for (int i = 0; i < total; i++) {
                    // popular o vetor com os numeros informado pelo usuario
                    printf("Informe um numero: ");
                    scanf("%d", &numeros[i]);
                }

                 // usei o bubble sort para ordenar pois gostomo mais dele por ser mais simples 
                 // e para numeros pequenos nao precisa de uma otimizacao em relaçao ao tempo
                bubbleSort(numeros, total);

                printf("numeros ordenados:\n");
                for (int i = 0; i < total; i++) {
                    // mostra os numeros de forma ordenada apos o sort
                    printf("%d ", numeros[i]);
                }
                 // coloca a quebra de linha apos o final da ordenção para ficar mais facil a vizualição
                printf("\n");
                break;
            }

            default:
                // caso o usuario coloque um valor diferente de 1 ou 2 
                printf("opção invalida\n");
                break;
        }
            //verificar se o usuario deseja continuar os testes 
        printf("deseja fazer de novo? 1 para continuar, 2 para parar: ");
        int continuar;
        scanf("%d", &continuar);

        if (continuar != 1) {
            // usar a variavel continuar alterar o programa para 0 caso  e assim encerrar o loop do while
            programa = 0;
        }
    }

    return 0;
}
