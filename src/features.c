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
    int R, G, B, formule; 

    if (read_image_data(filename, &data, &R, &G, &B) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
    }
    
    formule = 1*3;
    R=data[formule], G=data[formule+1], B=data[formule+2];
    printf(": %d, %d, %d\n", R, G, B);

}

void max_pixel(char* filename) {
    printf("max_pixel");
    unsigned char* data;
    int max_sum = 0;
    int max_x = 0, max_y = 0;
    pixelRGB max_pixel_rgb = {0, 0, 0};
    int height, width, channel_count, x, y;
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
        return;
    }
    
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
            int current_sum = current_pixel->R + current_pixel->G + current_pixel->B;
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_x = x;
                max_y = y;
                max_pixel_rgb = *current_pixel;
            }
        }
    }
    
    printf(" (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel_rgb.R, max_pixel_rgb.G, max_pixel_rgb.B);
}

void min_pixel(char* filename) {
    printf("min_pixel");
    unsigned char* data;
    int min_sum = 256*3+1;
    int min_x, min_y;
    pixelRGB min_pixel_rgb;
    int height, width, channel_count, x, y;
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
        return;
    }
    
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixelRGB* current_pixel = get_pixel(data, width, height, channel_count, x, y);
            int current_sum = current_pixel->R + current_pixel->G + current_pixel->B;
            
            if (current_sum < min_sum) {
                min_sum = current_sum;
                min_x = x;
                min_y = y;
                min_pixel_rgb = *current_pixel;
            }
        }
    }
    
    printf(" (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel_rgb.R, min_pixel_rgb.G, min_pixel_rgb.B);
}

void max_component(char *filename, char component){
    printf("max_component %c", component);

    unsigned char* data;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
            printf("Erreur avec le fichier: %s\n", filename);
        }

    int max_value = -1;
    int max_x = 0;
    int max_y = 0;
   
    for(int i=0; i< height; i++){
        for (int j = 0; j < width; j++) {
            pixelRGB *px = get_pixel(data, width, height, channels, j, i);

            int valeurmax = 0;
             if (component == 'R') {
                valeurmax = (*px).R;
            } else if (component == 'G') {
                valeurmax = (*px).G;
            } else if (component == 'B') {
                valeurmax = (*px).B;
            }

            if (valeurmax > max_value) {
                max_value = valeurmax;
                max_x = j;
                max_y = i;
            }
        }
    }
    printf(" (%d, %d): %d\n", max_x, max_y, max_value);
}

void min_component(char *filename, char component){
    printf("min_component %c", component);

    unsigned char* data;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
            printf("Erreur avec le fichier: %s\n", filename);
        }

    int min_value = 256; /*On a repris la même structure que pour max_compennet mais on commence ici à 256.*/
    int min_x = 0;
    int min_y = 0;
   
    for(int i=0; i< height; i++){
        for (int j = 0; j < width; j++) {
            pixelRGB *px = get_pixel(data, width, height, channels, j, i);

            int valeurmin = 0;
             if (component == 'R') {
                valeurmin = (*px).R;
            } else if (component == 'G') {
                valeurmin = (*px).G;
            } else if (component == 'B') {
                valeurmin = (*px).B;
            }

            if (valeurmin < min_value) {
                min_value = valeurmin;
                min_x = j;
                min_y = i;
            }
        }
    }
    printf(" (%d, %d): %d\n", min_x, min_y, min_value);
}