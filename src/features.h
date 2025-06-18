#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(char* filename);
void first_pixel(char* filename);
void tenth_pixel (char *source_path);
void second_line(char* filename);
void max_pixel (char* filename);
void min_pixel (char* filename);
void max_component(char * filename, char compoenent);
void min_component(char * filename, char compoenent);
void start_report(char *filename);
void color_red(char *filename);
void color_green(char *filename);
void color_blue(char *filename);
void color_gray(char *filename);
void color_invert(char *filename);
void color_gray_luminance(char *filename);
void color_desaturate(char *filename);
void scale_crop(char* filename, int center_x, int center_y, int crop_width, int crop_height);
void scale_nearest(char* filename, float scale);
void rotate_cw(char *filename);
#endif
