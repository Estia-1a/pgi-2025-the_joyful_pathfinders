#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char* filename) {
    printf("dimension");

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
    }
    else {
        printf(": %d, %d \n", width, height);
        free_image_data(data);
    }
}
void first_pixel(char* filename) {
    printf("first_pixel");

    unsigned char* data;
    int R, G, B;

    if (read_image_data(filename, &data, &R, &G, &B) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
    }
    else {
        R = data[0], G = data[1], B = data[2];
        printf(": %d, %d, %d\n", R, G, B);
    }
}
void tenth_pixel(char *source_path){
    printf("tenth_pixel");

    unsigned char* data;
    int R, G, B;

    if (read_image_data(source_path, &data, &R, &G, &B) == 0) {
        printf("Erreur avec le fichier: %s \n", source_path);
    }
    else {
        R=data[27], G=data[28], B=data[29];
        printf(": %d, %d, %d", R, G, B);
    }
}
void second_line(char* filename) {
    printf("second_line");

    unsigned char* data;
    int R, G, B, formule, width;

    formule = width*3;

    if (read_image_data(filename, &data, &R, &G, &B) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
    }
    else {
        R=data[formule], G=data[formule+1], B=data[formule+2];
        printf(": %d, %d, %d\n", R, G, B);
    }
}

void max_pixel(char* filename) {
    printf("max_pixel");
    unsigned char* data;
    int max_sum = 0;
    int max_x = 0, max_y = 0;
    pixelRGB max_pixel_rgb = {0, 0, 0};  // Fixed: proper variable declaration
    int height, width, channel_count, x, y;
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
        return;
    }
    
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixelRGB current_pixel = getPixel(data, width, channel_count, x, y);
            int current_sum = current_pixel.R + current_pixel.G + current_pixel.B;
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_x = x;
                max_y = y;
                max_pixel_rgb = current_pixel;
            }
        }
    }
    
    printf(" (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel_rgb.R, max_pixel_rgb.G, max_pixel_rgb.B);
}