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

void helloWorld()
{
    printf("Hello World !");
}

void dimension(const char *fichier)
{
    unsigned char *data = NULL;
    int w = 0, h = 0, c = 0;
    if (read_image_data(fichier, &data, &w, &h, &c) != 0)
    {
        printf("dimension: %d, %d\n", w, h);
        free_image_data(data);
    }
    else
    {
        printf("Fail to open %s\n", fichier);
    }
}
void first_pixel(char *fichier)
{

    unsigned char *data = NULL;
    int hauteur = 0, largeur = 0, c = 0;

    if (read_image_data(fichier, &data, &hauteur, &largeur, &c))
    {
        if (c < 3)
        {
            printf("ton image ne contient pas assez de channel");
        }
        else
        {
            unsigned char r = data[0];
            unsigned char g = data[1];
            unsigned char b = data[2];

            printf("first_pixel: %d, %d, %d", r, g, b);
        }
    }
    else
    {
        fprintf(stderr, "je ne peux pas lire ton image %s", fichier);
    }
}

void tenth_pixel(char *fichier)
{

    unsigned char *data = NULL;
    int hauteur = 0, largeur = 0, c = 0;

    if (read_image_data(fichier, &data, &hauteur, &largeur, &c))
    {
        if (c < 3)
        {
            printf("ton image ne contient pas assez de channel");
        }
        else
        {
            unsigned char r = data[27];
            unsigned char g = data[28];
            unsigned char b = data[29];

            printf("tenth_pixel: %d, %d, %d", r, g, b);
        }
    }
    else
    {
        fprintf(stderr, "je ne peux pas lire ton image %s", fichier);
    }

    if (data != NULL)
    {
        free(data);
    }
}

void print_pixel(char *filename, int x, int y)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    pixelRGB *pixel = get_pixel(data, width, height, n, x, y);
    if (pixel == NULL)
    {
        fprintf(stderr, "Coordonnées (%d, %d) hors limites\n", x, y);
    }
    else
    {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->V, pixel->B);
    }
}
