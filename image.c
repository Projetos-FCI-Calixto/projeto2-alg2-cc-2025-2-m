#include <stdio.h>
#include <stdlib.h>
#include "image.h"

Image* create_image(int width, int height) {
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    
    img->pixels = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = (int*)malloc(width * sizeof(int));
    }
    
    return img;
}

void free_image(Image *img) {
    if (img == NULL) return;
    
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

Image* read_manual_input() {
    int width, height;
    
    printf("=== CODIFICADOR DE IMAGENS BINARIAS ===\n\n");
    printf("Informe a largura da imagem: ");
    scanf("%d", &width);
    printf("Informe a altura da imagem: ");
    scanf("%d", &height);
    
    if (width <= 0 || height <= 0 || width > 1024 || height > 768) {
        printf("Erro: Dimensoes invalidas. Use valores entre 1x1 e 1024x768\n");
        return NULL;
    }
    
    Image *img = create_image(width, height);
    
    printf("\nInforme os pixels (0 para branco, 1 para preto), linha por linha:\n");
    for (int i = 0; i < height; i++) {
        printf("Linha %d: ", i + 1);
        for (int j = 0; j < width; j++) {
            int pixel;
            scanf("%d", &pixel);
            if (pixel != 0 && pixel != 1) {
                printf("Erro: Pixel deve ser 0 ou 1\n");
                free_image(img);
                return NULL;
            }
            img->pixels[i][j] = pixel;
        }
    }
    
    return img;
}
