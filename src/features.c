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

void second_line(char *filename, int x, int y)
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
        printf("second_line: %d, %d, %d\n", pixel->R, pixel->V, pixel->B);
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

    free(data);
}

void max_pixel(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int max_sum = -1;
    int max_x = 0, max_y = 0;
    unsigned int max_R = 0, max_V = 0, max_B = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, n, x, y);
            if (pixel != NULL)
            {
                int sum = pixel->R + pixel->V + pixel->B;
                if (sum > max_sum)
                {
                    max_sum = sum;
                    max_x = x;
                    max_y = y;
                    max_R = pixel->R;
                    max_V = pixel->V;
                    max_B = pixel->B;
                }
            }
        }
    }

    printf("max_pixel (%d, %d): %u, %u, %u\n", max_x, max_y, max_R, max_V, max_B);
}

void min_pixel(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int min_sum = 255 * 3 + 1;
    int min_x = 0, min_y = 0;
    unsigned int min_R = 0, min_V = 0, min_B = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, n, x, y);
            if (pixel != NULL)
            {
                int sum = pixel->R + pixel->V + pixel->B;
                if (sum < min_sum)
                {
                    min_sum = sum;
                    min_x = x;
                    min_y = y;
                    min_R = pixel->R;
                    min_V = pixel->V;
                    min_B = pixel->B;
                }
            }
        }
    }

    printf("min_pixel (%d, %d): %u, %u, %u\n", min_x, min_y, min_R, min_V, min_B);
}

void color_red(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int size = width * height * n;

    for (int i = 0; i < size; i += n)
    {

        unsigned char r = data[i];
        data[i] = r;
        data[i + 1] = 0;
        data[i + 2] = 0;
    }

    if (!write_image_data("image_out.bmp", data, width, height))
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'image de sortie.\n");
    }
}

void color_blue(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int size = width * height * n;

    for (int i = 0; i < size; i += n)
    {
        unsigned char b = data[i + 2];

        data[i] = 0;
        data[i + 1] = 0;
        data[i + 2] = b;
    }

    if (!write_image_data("image_out.bmp", data, width, height))
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'image de sortie.\n");
    }
}

void color_green(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int size = width * height * n;

    for (int i = 0; i < size; i += n)
    {
        unsigned char v = data[i + 1];

        data[i] = 0;
        data[i + 1] = v;
        data[i + 2] = 0;
    }

    if (!write_image_data("image_out.bmp", data, width, height))
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'image de sortie.\n");
    }
}

void color_gray(char *filename)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    int size = width * height * n;

    for (int i = 0; i < size; i += n)
    {
        unsigned char r = data[i];
        unsigned char v = data[i + 1];
        unsigned char b = data[i + 2];

        unsigned char gray = (unsigned char)(0.299 * r + 0.587 * v + 0.114 * b);

        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }

    if (!write_image_data("image_out.bmp", data, width, height))
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'image de sortie.\n");
    }
}

int inverser(const char *fichier1, const char *fichier2)
{
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(fichier1, &data, &width, &height, &channel_count))
    {
        fprintf(stderr, "Erreur : Impossible de lire l'image %s\n", fichier1);
        return 0;
    }

    int taille = width * height * channel_count;
    for (int i = 0; i < taille; i++)
    {
        data[i] = 255 - data[i];
    }

    if (!write_image_data(fichier2, data, width, height))
    {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image %s\n", fichier2);
        free(data);
        return 0;
    }

    free(data);
    return 1;
}

int color_gray_luminance(const char *fichier1, const char *fichier2)
{
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(fichier1, &data, &width, &height, &channel_count))
    {
        fprintf(stderr, "Erreur lors de la lecture de l'image : %s\n", fichier1);
        return 0;
    }

    int pixel_count = width * height;

    for (int i = 0; i < pixel_count; ++i)
    {
        unsigned char r = data[i * 3];
        unsigned char v = data[i * 3 + 1];
        unsigned char b = data[i * 3 + 2];

        unsigned char gray = (unsigned char)(0.21 * r + 0.72 * v + 0.07 * b);

        data[i * 3] = gray;
        data[i * 3 + 1] = gray;
        data[i * 3 + 2] = gray;
    }

    if (!write_image_data(fichier2, data, width, height))
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'image : %s\n", fichier2);
        free(data);
        return 0;
    }

    free(data);
    return 1;
}

int color_desaturate(const char *fichier1, const char *fichier2)
{
    unsigned char *data;
    int width, height, channel_count;

    if (!read_image_data(fichier1, &data, &width, &height, &channel_count))
    {
        printf("Erreur : impossible de lire %s\n", fichier1);
        return 0;
    }

    int size = width * height;

    for (int i = 0; i < size; i++)
    {
        unsigned char R = data[i * channel_count + 0];
        unsigned char V = data[i * channel_count + 1];
        unsigned char B = data[i * channel_count + 2];

        unsigned char min_val = (R < V) ? ((R < B) ? R : B) : ((V < B) ? V : B);
        unsigned char max_val = (R > V) ? ((R > B) ? R : B) : ((V > B) ? V : B);

        unsigned char new_val = (min_val + max_val) / 2;

        data[i * channel_count + 0] = new_val;
        data[i * channel_count + 1] = new_val;
        data[i * channel_count + 2] = new_val;
    }

    if (!write_image_data(fichier2, data, width, height))
    {
        printf("Erreur : impossible d'écrire %s\n", fichier2);
        free(data);
        return 0;
    }

    free(data);
    return 1;
}

unsigned char bilinear_interpolate(float x, float y, unsigned char q11, unsigned char q21, unsigned char q12, unsigned char q22)
{
    float val = q11 * (1 - x) * (1 - y) +
                q21 * x * (1 - y) +
                q12 * (1 - x) * y +
                q22 * x * y;

    if (val < 0)
        val = 0;
    if (val > 255)
        val = 255;

    return (unsigned char)(val + 0.5f); 
}

int scale_bilinear(const char *input_file, const char *output_file, float scale)
{
    unsigned char *data_in = NULL;
    int width_in, height_in, channel_count;

    if (!read_image_data(input_file, &data_in, &width_in, &height_in, &channel_count))
    {
        printf("Erreur lors de la lecture de l'image.\n");
        return 0;
    }

    int width_out = (int)(width_in * scale);
    int height_out = (int)(height_in * scale);

    unsigned char *data_out = malloc(width_out * height_out * channel_count);
    if (!data_out)
    {
        printf("Erreur d'allocation mémoire.\n");
        free(data_in);
        return 0;
    }

    for (int y_out = 0; y_out < height_out; y_out++)
    {
        float y_in = y_out / scale;
        int y0 = (int)y_in;
        int y1 = (y0 + 1 < height_in) ? y0 + 1 : y0;
        float dy = y_in - y0;

        for (int x_out = 0; x_out < width_out; x_out++)
        {
            float x_in = x_out / scale;
            int x0 = (int)x_in;
            int x1 = (x0 + 1 < width_in) ? x0 + 1 : x0;
            float dx = x_in - x0;

            for (int c = 0; c < channel_count; c++)
            {
                unsigned char q11 = data_in[(y0 * width_in + x0) * channel_count + c];
                unsigned char q21 = data_in[(y0 * width_in + x1) * channel_count + c];
                unsigned char q12 = data_in[(y1 * width_in + x0) * channel_count + c];
                unsigned char q22 = data_in[(y1 * width_in + x1) * channel_count + c];

                data_out[(y_out * width_out + x_out) * channel_count + c] =
                    bilinear_interpolate(dx, dy, q11, q21, q12, q22);
            }
        }
    }

    if (!write_image_data(output_file, data_out, width_out, height_out))
    {
        printf("Erreur lors de l'écriture de l'image.\n");
        free(data_in);
        free(data_out);
        return 0;
    }

    free(data_in);
    free(data_out);
    return 1;
}