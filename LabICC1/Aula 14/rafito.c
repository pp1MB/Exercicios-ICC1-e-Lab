#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char palavra[30], nome[9];
    scanf("%s %s", palavra, nome);
    
    FILE *fp = fopen(nome, "rb");
    
    int tam;
    fseek(fp, 0, SEEK_END);
    tam = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *texto = (char *) malloc(tam + 1);
    fread(texto, sizeof(char), tam, fp);

    char *temp = strstr(texto, palavra);

    for(int i=0; texto[i] != '\0'; i++){

        if(texto + i == temp){
            i += strlen(palavra);

            if(temp[strlen(palavra)] == ' ')
                i++;
        }

        printf("%c", texto[i]);
    }

    free(texto);
    texto = NULL;

    fclose(fp);
    
    return 0;
}