#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/

typedef struct {
   unsigned char R, G, B ;
} pixelRGB;

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
void print_pixel(char *filename, int x, int y);

void set_pixel(unsigned char* data, unsigned int width, unsigned int channels, unsigned int x, unsigned int y, pixelRGB pixel);
#endif

