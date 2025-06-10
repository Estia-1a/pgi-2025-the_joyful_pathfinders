#include <estia-image.h>
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    if(x>=width || y>=height || n<3){
        return NULL;
    }else if(data == NULL){
        return NULL;
    }else{
        unsigned int i= (y* width+x)*n;
        return (pixelRGB*) &data[i] ; 
    }
}

void print_pixel(char *filename, int x, int y){
    
    unsigned char *data = NULL;
    int width, height, channels;
    
    if(read_image_data(filename, &data, &width, &height, &channels) == 0){
        printf("Erreur avec le fichier");
    }
    pixelRGB* px = get_pixel(data, width, height, channels, x, y);
    if (px == NULL) {
        printf("Erreur avec les coordonnées ");
    }

    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, px->R, px->G, px->B);

}




