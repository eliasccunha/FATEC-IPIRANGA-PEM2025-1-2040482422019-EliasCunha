#include<stdio.h>

typedef struct{
    char nome[50];
    float nota;
} Alunos;


void topQuinze(Alunos nomes[], int candidatos){
    for(int i = 0; i < candidatos; i++){
        for(int j = 0; j < candidatos - i - 1; j++){
            if(nomes[j].nota < nomes[j + 1].nota){

                Alunos temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }

}


int main(){
int candidatos;

printf("Informe o numero total de candidatos: ");
    scanf("%d", &candidatos);
    getchar();
    
    int i, j, k, l, m; 
    float pe, ac, pp, eb;
    float maior, menor, temp;
    
    Alunos nomes[candidatos];
    for(i = 0;i < candidatos; i++){
        printf("informe o nome do candidato: ");
        fgets(nomes[i].nome, sizeof(nomes[i].nome), stdin);

        float menor = 10.0, maior = 0.0;
        float pe = 0.0, ac = 0.0, pp = 0.0, eb = 0.0;
        
        for(j = 0; j < 4; j++){
            printf("Insira a nota de Prova Escrita numero %d: ", j + 1);
            scanf("%f", &temp);
            if(temp > maior){
                maior = temp;
            }
            if(temp < menor){
                menor = temp;
            }
            pe += temp;
        }
        pe -= (maior + menor);
        menor = 10.0, maior = 0.0;
      
        
        for( k = 0; k < 5; k++){
        printf("Insira a nota de Analise Curricular numero %d: ", k + 1);
            scanf("%f", &temp);
            
            if(temp > maior){
                maior = temp;
            }
            if(temp < menor){
                menor = temp;
            }
            ac += temp;
        }
        ac -= (maior + menor);
        menor = 10.0, maior = 0.0;
        
        
        for(l = 0; l < 10; l++){
            printf("Insira a nota de Prova Pratica numero %d : ", l + 1);
            scanf("%f", &temp);
            if(temp > maior){
                maior = temp;
            }
            if(temp < menor){
                menor = temp;
            }
            pp += temp;
        }
        pp -= (maior + menor);
        menor = 10.0, maior = 0.0;
        
        for(m = 0; m < 3; m++){
            printf("Insira a nota de Entrevista em Banca Avaliadora numero %d : ", m + 1);
            scanf("%f", &temp);
            if(temp > maior){
                maior = temp;
            }
            if(temp < menor){
                menor = temp;
            }
            eb += temp;
            
        }
        eb -= (maior + menor);
        nomes[i].nota = ((pe * 0.3) + (ac * 0.1) + (pp * 0.4) + (eb * 0.2));
        getchar(); 
    }
    
    topQuinze (nomes, candidatos);

    
    printf("---classificacao---\n");
    
    
    for( i = 0; i < candidatos && i < 15;i++){
        printf(" [%d] nota: %.2f  Nome: %s" , i+1, nomes[i].nota, nomes[i].nome);
    }

    return 0;
}