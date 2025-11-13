#include <stdlib.h>
#include <string.h>
#include "encoder.h"

int is_uniform(const Image *img, int start_x, int start_y, int width, int height) {
    if (width <= 0 || height <= 0) return 1;
    
    int first_pixel = img->pixels[start_y][start_x];
    
    for (int i = start_y; i < start_y + height; i++) {
        for (int j = start_x; j < start_x + width; j++) {
            if (img->pixels[i][j] != first_pixel) {
                return 0;
            }
        }
    }
    return 1;
}

void encode_region(const Image *img, int start_x, int start_y, int width, int height, CodeBuffer *buffer) {
    if (width <= 0 || height <= 0) return;
    
    if (is_uniform(img, start_x, start_y, width, height)) {
        char code = img->pixels[start_y][start_x] ? 'P' : 'B';
        append_to_buffer(buffer, code);
        return;
    }
    
    append_to_buffer(buffer, 'X');
    
    // Calcular divisões (respeitando pixels inteiros)
    int left_width = (width + 1) / 2;
    int right_width = width - left_width;
    int top_height = (height + 1) / 2;
    int bottom_height = height - top_height;
    
    // ORDEM CORRIGIDA conforme o PDF:
    // 1º Quadrante: superior esquerdo
    if (top_height > 0 && left_width > 0) {
        encode_region(img, start_x, start_y, left_width, top_height, buffer);
    }
    
    // 2º Quadrante: superior direito  
    if (top_height > 0 && right_width > 0) {
        encode_region(img, start_x + left_width, start_y, right_width, top_height, buffer);
    }
    
    // 3º Quadrante: inferior esquerdo
    if (bottom_height > 0 && left_width > 0) {
        encode_region(img, start_x, start_y + top_height, left_width, bottom_height, buffer);
    }
    
    // 4º Quadrante: inferior direito
    if (bottom_height > 0 && right_width > 0) {
        encode_region(img, start_x + left_width, start_y + top_height, right_width, bottom_height, buffer);
    }
}

char* encode_image(const Image *img) {
    if (!img || img->width <= 0 || img->height <= 0) {
        return NULL;
    }
    
    CodeBuffer *buffer = create_code_buffer();
    encode_region(img, 0, 0, img->width, img->height, buffer);
    
    char *result = strdup(buffer->code);
    free_code_buffer(buffer);
    return result;
}
