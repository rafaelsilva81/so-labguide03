#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <elf.h>



int main() {
    Elf64_Ehdr header;

    FILE *fp;
    
    fp = fopen("elf_file", "rb");

   if(fp) {
        fread(&header, sizeof(header), 1, fp);
        printf("------ IDENTIFICAÇÃO --------\n");
        puts(header.e_ident);
        printf("------------------------------\n");
        fclose(fp);
   }
}

