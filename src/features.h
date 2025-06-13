#ifndef FEATURES_H
#define FEATURES_H

void helloWorld();

void dimension(const char *);

void first_pixel(char *);

void tenth_pixel(char *);

void second_line(char *filename, int x, int y);

void print_pixel(char *filename, int x, int y);

void max_pixel(char *filename);

void min_pixel(char *filename);

void color_red(char *filename);

void color_green(char *filename);

void color_blue(char *filename);

void color_gray(char *filename);

int inverser(const char *fichier1, const char *fichier2);

int color_gray_luminance(const char *fichier1, const char *fichier2);

int color_desaturate(const char *fichier1, const char *fichier2);

int scale_bilinear(const char *input_file, const char *output_file, float scale);
#endif
