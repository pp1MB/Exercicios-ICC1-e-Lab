#include <stdio.h>
#include <stdlib.h>

int main(void){
    char nome[13];
    scanf("%s", nome);
    
    FILE *fp = fopen(nome, "rb");
    fseek(fp, 0, SEEK_END);
    int tam = ftell(fp);
    char *text = (char *) malloc(tam);
    fseek(fp, 0, SEEK_SET);
    fread(text, sizeof(char), tam, fp);

    printf("%s", text);

    fclose(fp);
    free(text);
    text = NULL;
    return 0;
}