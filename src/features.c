#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
    unsigned char* data;
    int width, height, channels;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur avec le fichier: %s \n", filename);
        return;
    }

    int x = 0;
    int y = 1;
    int index = (y * width + x) * channels;

    int R = data[index];
    int G = data[index + 1];
    int B = data[index + 2];

    printf("second_line: %d, %d, %d\n", R, G, B);
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

    int min_value = 255; /*On a repris la même structure que pour max_compennet mais on commence ici à 256.*/
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

void start_report(char *filename){

/*ouvrir le fichier*/
    FILE *f = fopen("stat_report.txt", "w");

/*les fonctions*/
    fprintf(f, "max_pixel "); /*note: fprint permet d'ecrire du texte dans un fichier défini. On écrit ici dans le fichier f*/
    max_pixel(filename); 
    fprintf(f, "\n\n");

    fprintf(f, "min_pixel ");
    min_pixel(filename);
    fprintf(f, "\n\n");

    fprintf(f, "max_component R ");
    max_component(filename, 'R');
    fprintf(f, "\n\n");

    fprintf(f, "max_component G ");
    max_component(filename, 'G');
    fprintf(f, "\n\n");

    fprintf(f, "max_component B ");
    max_component(filename, 'B');
    fprintf(f, "\n\n");

    fprintf(f, "min_component R ");
    min_component(filename, 'R');
    fprintf(f, "\n\n");

    fprintf(f, "min_component G ");
    min_component(filename, 'G');
    fprintf(f, "\n\n");

    fprintf(f, "min_component B ");
    min_component(filename, 'B');
    
    fclose(f); /*fermer le fichier texte*/
}

void color_red(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->G = 0;
            pixel->B = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_green(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->R = 0;
            pixel->B = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_blue(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->R = 0;
            pixel->G = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char value = (pixel->R + pixel->G + pixel->B)/ 3;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_invert(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            pixel->R = 255 - pixel->R;
            pixel->G = 255 - pixel->G;
            pixel->B = 255 - pixel->B;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray_luminance(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
   
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char value = (unsigned char)(0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B);
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_desaturate(char *filename) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

            unsigned char min_val = pixel->R < pixel->G ? (pixel->R < pixel->B ? pixel->R : pixel->B) : (pixel->G < pixel->B ? pixel->G : pixel->B);
            unsigned char max_val = pixel->R > pixel->G ? (pixel->R > pixel->B ? pixel->R : pixel->B) : (pixel->G > pixel->B ? pixel->G : pixel->B);
            unsigned char new_val = (min_val + max_val) / 2;

            pixel->R = new_val;
            pixel->G = new_val;
            pixel->B = new_val;
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void scale_crop(char* filename, int center_x, int center_y, int crop_width, int crop_height) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur lecture image\n");
        return;
    }

    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;

    int offset_x = (start_x < 0) ? -start_x : 0;
    int offset_y = (start_y < 0) ? -start_y : 0;

    start_x = (start_x < 0) ? 0 : start_x;
    start_y = (start_y < 0) ? 0 : start_y;

    int max_width = (start_x + crop_width > width) ? width - start_x : crop_width;
    int max_height = (start_y + crop_height > height) ? height - start_y : crop_height;

    unsigned char* cropped = calloc(crop_width * crop_height * channels, sizeof(unsigned char));

    for (int y = 0; y < max_height; y++) {
        for (int x = 0; x < max_width; x++) {
            pixelRGB* src_pixel = get_pixel(data, width, height, channels, start_x + x, start_y + y);
            if (src_pixel) {
                pixelRGB p = *src_pixel;
                set_pixel(cropped, crop_width, channels, x + offset_x, y + offset_y, p);
            }
        }
    }

    write_image_data("image_out.bmp", cropped, crop_width, crop_height);
    free_image_data(data);
    free(cropped);
}

void scale_nearest(char* filename, float scale) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur : impossible de lire l’image.\n");
        return;
    }

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);

    unsigned char* resized = malloc(new_width * new_height * channels);
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)((float)x / scale);
            int src_y = (int)((float)y / scale);

            if (src_x >= width) src_x = width - 1;
            if (src_y >= height) src_y = height - 1;

            pixelRGB* p = get_pixel(data, width, height, channels, src_x, src_y);
            set_pixel(resized, new_width, channels, x, y, *p);
        }
    }
    write_image_data("image_out.bmp", resized, new_width, new_height);
    free_image_data(data);
    free(resized);
}

void scale_bilinear(char* filename, float scale) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur : impossible de lire l’image.\n");
        return;
    }

    int new_width = width * scale;
    int new_height = height * scale;
    unsigned char* output = malloc(new_width * new_height * channels);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            float gx = x / scale;
            float gy = y / scale;

            int x1 = (int)gx;
            int y1 = (int)gy;
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            float dx = gx - x1;
            float dy = gy - y1;

            pixelRGB q11 = *get_pixel(data, width, height, channels, x1, y1);
            pixelRGB q21 = *get_pixel(data, width, height, channels, x2 >= width ? width - 1 : x2, y1);
            pixelRGB q12 = *get_pixel(data, width, height, channels, x1, y2 >= height ? height - 1 : y2);
            pixelRGB q22 = *get_pixel(data, width, height, channels, x2 >= width ? width - 1 : x2, y2 >= height ? height - 1 : y2);
            pixelRGB result;
            result.R = (unsigned char)(
                (1 - dx) * (1 - dy) * q11.R +
                dx * (1 - dy) * q21.R +
                (1 - dx) * dy * q12.R +
                dx * dy * q22.R);

            result.G = (unsigned char)(
                (1 - dx) * (1 - dy) * q11.G +
                dx * (1 - dy) * q21.G +
                (1 - dx) * dy * q12.G +
                dx * dy * q22.G);

            result.B = (unsigned char)(
                (1 - dx) * (1 - dy) * q11.B +
                dx * (1 - dy) * q21.B +
                (1 - dx) * dy * q12.B +
                dx * dy * q22.B);

            set_pixel(output, new_width, channels, x, y, result);
        }
    }
    write_image_data("image_out.bmp", output, new_width, new_height);
    free_image_data(data);
    free(output);
    printf("Image originale : %dx%d\n", width, height);
    printf("Image redimensionnée : %dx%d (échelle %.2f)\n", new_width, new_height, scale);
}

void rotate_cw(char* filename){
    unsigned char* data;
    int width, height, channels;

    read_image_data(filename, &data, &width, &height, &channels);

    int new_width=height;
    int new_height=width;

    unsigned char* rotated_image=malloc(new_width*new_height*channels); /*On créer un nouveau tableau pour contenir l'image tournée*/

    int x=0;
    int y=0;
    for (y=0; y<height ; y++){
        for(x=0 ; x<width ; x++){
            for(int c=0; c<channels; c++){
                int new_x;
                new_x= height-1-y;
                int new_y;
                new_y = x;

                rotated_image[(new_y*new_width+new_x)*channels+c]= data[(y * width + x) * channels + c];

            }
        }
    }
     write_image_data("image_out.bmp", rotated_image, new_width, new_height); /*Pour ecrire la nouvelle image*/
}

void mirror_horizontal(char* filename) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur : impossible de lire l'image\n");
        return;
    }

    unsigned char* mirrored = malloc(width * height * channels);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_x = width - 1 - x;
            pixelRGB* src = get_pixel(data, width, height, channels, src_x, y);
            set_pixel(mirrored, width, channels, x, y, *src);
        }
    }

    write_image_data("image_out.bmp", mirrored, width, height);
}

void rotate_acw(char* filename){
    unsigned char* data;
    int width, height, channels;

    read_image_data(filename, &data, &width, &height, &channels);

    int new_width=height;
    int new_height=width;

    unsigned char* rotated_image=malloc(new_width*new_height*channels); /*On créer un nouveau tableau pour contenir l'image tournée*/

    int x=0;
    int y=0;
    for (y=0; y<height ; y++){
        for(x=0 ; x<width ; x++){
            for(int c=0; c<channels; c++){
                int new_x;
                new_x= y;
                int new_y;
                new_y = width-1-x;

                rotated_image[(new_y*new_width+new_x)*channels+c]= data[(y * width + x) * channels + c];

            }
        }
    }
     write_image_data("image_out.bmp", rotated_image, new_width, new_height); /*Pour ecrire la nouvelle image*/
}
void mirror_vertical(char* filename) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(filename, &data, &width, &height, &channels) == 0) {
        printf("Erreur : impossible de lire l'image\n");
        return;
    }

    unsigned char* mirrored = malloc(width * height * channels);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_y = height - 1 - y;
            pixelRGB* src = get_pixel(data, width, height, channels, x, src_y);
            set_pixel(mirrored, width, channels, x, y, *src);
        }
    }
    write_image_data("image_out.bmp", mirrored, width, height);
}