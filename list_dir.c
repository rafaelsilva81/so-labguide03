#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void list(char *path) {

    DIR *dir = opendir(path);
    struct dirent *start;

    while((start = readdir(dir)) != NULL) {
         if (start->d_type == DT_DIR) {
            char next_dir[2048];
            if (strcmp(start->d_name, ".") != 0 && strcmp(start->d_name, "..") != 0) {
                snprintf(next_dir, sizeof(next_dir), "%s/%s", path, start->d_name);
                //printf("%s", next_dir);
                printf("   === %s ===   \n", start->d_name);
                list(next_dir);
            }
            
        } else {
            printf("     * %s \n", start->d_name);
        }
    }

    closedir(dir);
  
}

int main() {
    char dir[2048] = "/home/rafael81/Teste";
    printf("Diretório inicial : %s\n", dir); 
    list(dir);
    return 0;
}
