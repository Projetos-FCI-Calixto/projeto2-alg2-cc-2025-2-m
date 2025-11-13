#ifndef ENCODER_H
#define ENCODER_H

#include "image.h"
#include "code_buffer.h"

int is_uniform(const Image *img, int start_x, int start_y, int width, int height);
void encode_region(const Image *img, int start_x, int start_y, int width, int height, CodeBuffer *buffer);
char* encode_image(const Image *img);

#endif
