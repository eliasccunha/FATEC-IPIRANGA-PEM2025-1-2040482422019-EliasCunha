/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Recursividade                    *
 * Data - 27/03/2025                                      *
 * Autor: Elias Cesario da Cunha                          *
 *--------------------------------------------------------*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>

void listar_arquivos(const char *caminho, int nivel) {
    struct dirent *entrada;
    DIR *dir = opendir(caminho);
    
    if (dir == NULL) {
        printf("Erro!! nao foi possivel abrir o diretorio: %s\n", caminho);
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        // Ignora "." e ".."
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        // Imprime com recuo para indicar a hierarquia
        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
        printf("[]==== %s\n", entrada->d_name);

        // Se for um diretório, chama recursivamente
        if (entrada->d_type == DT_DIR) {
            char novo_caminho[1024];
            snprintf(novo_caminho, sizeof(novo_caminho), "%s/%s", caminho, entrada->d_name);
            listar_arquivos(novo_caminho, nivel + 1);
        }
    }

    closedir(dir);
}

int main() {
    const char *caminho_inicial = "."; // Começa no diretório atual
    printf("Arvore de diretorios:\n");
    listar_arquivos(caminho_inicial, 0);
    return 0;
}
