#include <stdio.h>
#include <stdlib.h>

int main(void){
    int cont = 0;
    char nome[6], palavra[10];
    scanf("%s %s", nome, palavra);

    FILE *fp = fopen(nome, "r");

    char temp[20];
    while(!feof(fp)){
        fscanf(fp, "%s", temp);

        for(int i = 0; palavra[i] != '\0'; i++){
            if(temp[i] != palavra[i] && abs(palavra[i] - temp[i]) != 32)
                break;
            else if(palavra[i+1] == '\0'){
                cont++;
            }
        }
    }

    printf("quantidade: %d", cont);
    fclose(fp);

    return 0;
}