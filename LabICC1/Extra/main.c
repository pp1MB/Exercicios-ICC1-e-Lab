#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* A struct 'imagem' reúne as principais informações *
 * que da imagem processada.                         */
typedef struct{
    char *nome;
    int x;
    int y;
    int max;
    int min;
    char tipo;
    unsigned char *pixels;
} imagem;

void *alocarMemoria(int size);
void liberarMemoria(imagem img);

void loadImage(imagem *img);
void saveImage(imagem img);

void logOp(imagem *img);
void calcMinMax(imagem *img);

int main(void){
    imagem img;
    loadImage(&img);
    logOp(&img);
    saveImage(img);
    liberarMemoria(img);

    return 0;
}

void *alocarMemoria(int size){
    void *p;
    if((p = malloc(size)) == NULL){
        printf("Erro ao alocar memória.");
        exit(1);
    }
    return p;
}

void liberarMemoria(imagem img){
    free(img.nome);
    img.nome = NULL;
    free(img.pixels);
    img.pixels = NULL;

    return;
}

/* A função 'loadImage' é responsável por passar todos os dados da imagem para dentro do programa. */
void loadImage(imagem *img){
    /* O nome é primeiro lido a partir de uma string estática e depois é passado dinamicamente para a struct. */
    char nome[30];
    scanf("%s", nome); 
    (*img).nome = (char *) alocarMemoria(sizeof(char) * (strlen(nome)+1));
    strcpy((*img).nome, nome);

    /* O arquivo com o nome passado a struct é aberto. */
    FILE *fp = fopen((*img).nome, "r");
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para leitura.");
        exit(1);
    }

    /* Leitura do tipo de arquivo. (2: Texto, 5: Binário) */
    fscanf(fp, "P%c\n", &(*img).tipo);

    /* Pulando a linha de comentário. */
    char c = fgetc(fp);
    while (c == '#') {
        while (fgetc(fp) != '\n');
        c = fgetc(fp);
    }
    ungetc(c, fp);

    /* Leitura das dimensões da imagem e do pixel de maior valor. */
    fscanf(fp, "%d %d\n%d\n", &(*img).x, &(*img).y, &(*img).max);

    /* Os pixels são passados para um vetor unidimensional alocado a partir das dimensões *
     * fornecidas anteriormente de formas diferentes dependendo do tipo do arquivo.       */
    (*img).pixels = (unsigned char *) alocarMemoria(sizeof(unsigned char) * (*img).x * (*img).y);
    
    if((*img).tipo == '2'){
        for(int i=0; i < (*img).x * (*img).y; i++){
            int pixel;
            fscanf(fp, "%d", &pixel);
            (*img).pixels[i] = (unsigned char) pixel;
        }
    } else if((*img).tipo == '5')
        fread((*img).pixels, sizeof(unsigned char), (*img).x * (*img).y, fp);

    fclose(fp);

    return;
}

/* A função 'saveImage' é responsável por passar as informações processadas no programa para dentro do arquivo original. */
void saveImage(imagem img){
    FILE *fp = fopen(img.nome, "w");
    if(fp == NULL){
        printf("Erro ao abrir o arquivo para escrita.");
        exit(1);
    }

    /* Imprimindo o cabeçalho.*/
    fprintf(fp, "P2\n# CREATOR: Image Generator SCC-222 – Lab ICC I\n%d %d\n%d\n", img.x, img.y, img.max);
    printf("P2\n# CREATOR: Image Generator SCC-222 – Lab ICC I\n%d %d\n%d\n", img.x, img.y, img.max);

    /* Imprimindo cada pixel. */
    for(int i = 0; i < img.x * img.y; i++){
        fprintf(fp, "%d\n", img.pixels[i]);
        printf("%d\n", img.pixels[i]);
    }

    fclose(fp);

    return;
}

/* A função 'logOp' é responsável pela operação de logaritmo e normalização realizada na imagem.*/
void logOp(imagem *img){
    double c = 255 / log(1 + (*img).max);

    /* Operação de logaritmo */
    for(int i = 0; i < (*img).x * (*img).y; i++)
        (*img).pixels[i] = (unsigned char) (c * log(1 + (*img).pixels[i]));
    
    calcMinMax(img);

    /* Normalização */
    for(int i = 0; i < (*img).x * (*img).y; i++)
        (*img).pixels[i] = (unsigned char) (((*img).pixels[i] - (*img).min) * 255 / ((*img).max - (*img).min));

    return;
}

/* A função 'calcMinMax' é responsável por procurar os pixeis de maior e menor valor na imagem.*/
void calcMinMax(imagem *img){
    (*img).min = (*img).pixels[0];
    (*img).max = (*img).pixels[0];

    for(int i = 1; i < (*img).x * (*img).y; i++){
        if((*img).min > (*img).pixels[i])
            (*img).min = (*img).pixels[i];
        if((*img).max < (*img).pixels[i])
            (*img).max = (*img).pixels[i];
    }

    return;
}