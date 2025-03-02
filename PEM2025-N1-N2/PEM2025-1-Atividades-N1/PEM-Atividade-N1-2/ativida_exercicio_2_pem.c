/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Estoque almoxarifado             *
 * Data - 02/03/1933                                      *
 * Autor: Elias Cesario da Cunha                          *
 *--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main()
{

    char estoque[3][10][5];
    int gaveta;
    char rua;
    int i, j;
    int confirmar = 1;
    int acao;

    int quantidadades[30];

    for (int i = 0; i < 30; i++)
    {
      quantidadades[i] = 0;
    }
  

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // preencher o o estoque com espaços vazios
            strcpy(estoque[i][j], "");
        }
    }
  

    while (1)
    {
    
       //instruçoes de comando de estoque
       printf("Para entradada de item em estoque digite 1\n");
       printf("Para retirada de item em estoque digite 2\n");
       printf("Para verificar o estoque digite 3\n");
       printf("Para fechar o Programa digite 4\n");
       printf("digite o numero: ");
        scanf("%d", &acao);    
            switch (acao)
            {
            case 1:
                // entrada de produto
                printf("informe a rua em qual ira armazenar o item A ,B OU C:");
                scanf(" %c", &rua);
                getchar();
                
                if (rua == 'A')
                {
                    i = 0;
                }
                else if (rua == 'B')
                {
                    i = 1;
                }
                else if (rua == 'C')
                {
                    i = 2;
                }

                printf("informe a gondola de 1 a 10:");
                scanf("%d", &j);
                j -= 1;
                getchar();

                if (strcmp(estoque[i][j], "") == 0)
                {
                    printf("Informe o codigo do produto de ate 4 caracteres: ");
                    scanf("%s", estoque[i][j]);
                    printf("item %s sera armazenado na RUA %c Gondola %d \n",estoque[i][j] ,rua, j +1);
                }
                else
                {
                    printf("ja tem o item %s armazenado neste local\n", estoque[i][j]);
                    printf("\n");
                }
                   

                break;

            case 2:
                // retirada de produtos
                printf("informe a rua em que ira retirar  o item A ,B OU C:");
                scanf(" %c", &rua);
                getchar();
                if (rua == 'A')
                {
                    i = 0;
                }
                else if (rua == 'B')
                {
                    i = 1;
                }
                else if (rua == 'C')
                {
                    i = 2;
                }

                printf("informe a gondola de (1 - 10):");
                scanf("%d", &j);
                j -= 1;
                getchar();

                if (strcmp(estoque[i][j], "") == 0)
                {
                    printf("Nenhum produto cadastrado neste local\n");
                    printf("\n");
                }
                else
                {
                    printf("quer realmente retirar o  item codigo: %s ?\n", estoque[i][j]);
                    printf("(1) para sim  ou (2) para nao?\n");
                    scanf("%d", &confirmar);
                    if (confirmar == 1)
                    {
                        printf("pedido de retirada confirmado!\n");
                        
                        printf("\n");
                    }
                    else
                    {
                        printf("pedido cancelado!\n");
                        printf("\n");
                    }
                
                    
                }
                // retirada
                break;

            case 3:
                // consulta estoque
                  for (i = 0; i < 3; i++) {
                    if (i == 0) printf("\n--- RUA A ---\n");
                    else if (i == 1) printf("\n--- RUA B ---\n");
                    else if (i == 2) printf("\n--- RUA C ---\n");

                    for (j = 0; j < 10; j++) {
                        if (strcmp(estoque[i][j], "") == 0) {
                            printf("Gondola %d: vazia\n", j + 1);
                        } else {
                            printf("Gondola %d: Código %s\n", j + 1, estoque[i][j]);
                        }
                    }
                }
                break;
            
            case 4:
             // Sair do programa
                printf("Fechando o programa...\n");
                return 0;
            
            default:
                printf("Opcao invalida\n");
            
                break;
            }
        }
    

    return 0;
}