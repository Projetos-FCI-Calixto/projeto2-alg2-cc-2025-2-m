#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "encoder.h"

int main() {
    printf("=== CODIFICADOR DE IMAGENS BINARIAS ===\n\n");
    
    Image *image = read_manual_input();
    
    if (!image) {
        printf("Erro: Não foi possível carregar a imagem\n");
        return 1;
    }
    
    char *code = encode_image(image);
    if (code) {
        printf("\n CODIGO GERADO: %s\n", code);
        free(code);
    } else {
        printf("\n Erro na codificação\n");
    }
    
    free_image(image);
    
    printf("\nPrograma finalizado!\n");
    return 0;
}
