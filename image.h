#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

Image* create_image(int width, int height);
void free_image(Image *img);
Image* read_manual_input();

#endif
