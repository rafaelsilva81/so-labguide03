#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main() {

    FILE *diff, *a1, *a2;
    char str1[256], str2[256];

    //Criação do arquivo diff.txt e abertura dos arquivos
    diff = fopen ("diff.txt", "w");
    a1 = fopen ("arquivo1.txt", "r");
    a2 = fopen ("arquivo2.txt", "r");

    while (fgets(str1, 256, a1) != NULL && fgets(str2, 256, a2) != NULL) {
        if(strcmp(str1,str2) != 0) {

             //As strings não são iguais
             if(strcmp(str1, "\n") != 0) { //Checa se a string não é vazia

                str1[strcspn(str1, "\n")] = 0; 
                /* 
                   Remove o caractere final de fim de linha, isso é feito para 
                   conseguir adicionar o colchete no final
                */

                fprintf(diff, "[%s]\n", str1); //Escreve no arquivo

             }
             if (strcmp(str2, "\n") != 0) {
                str2[strcspn(str2, "\n")] = 0;
                fprintf(diff, "[%s]\n", str2);
             }
        } else {
             //As strings são identicas
             if(strcmp(str1, "\n") != 0) {
                fprintf(diff, "%s", str1);
             }
        }
    }
    
    //Fechamento dos Arquivos
    fclose(a1);
    fclose(a2);
}
