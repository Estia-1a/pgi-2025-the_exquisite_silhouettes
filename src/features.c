#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"
#define MAX_WIDTH 10240
#define MAX_HEIGHT 10240
#define MAX_CHANNELS 4

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
        free(data);
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
        free(data);
    }
    else
    {
        fprintf(stderr, "je ne peux pas lire ton image %s", fichier);
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

int rotate_cw(const char *input_filename, const char *output_filename)
{
    unsigned char *input_data = NULL;
    unsigned char *output_data = NULL;
    int width, height, channels;
    int new_width, new_height;
    int x, y, input_idx, output_idx;
    int new_x, new_y;

    if (!read_image_data(input_filename, &input_data, &width, &height, &channels))
    {
        fprintf(stderr, "Erreur : Impossible de lire l'image %s\n", input_filename);
        return 0;
    }

    if (channels < 3)
    {
        fprintf(stderr, "Erreur : L'image doit avoir au moins 3 canaux\n");
        free(input_data);
        return 0;
    }

    new_width = height;
    new_height = width;

    output_data = (unsigned char *)malloc(new_width * new_height * channels);
    if (output_data == NULL)
    {
        fprintf(stderr, "Erreur : Allocation mémoire échouée\n");
        free(input_data);
        return 0;
    }
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            input_idx = (y * width + x) * channels;

            new_x = height - 1 - y;
            new_y = x;

            output_idx = (new_y * new_width + new_x) * channels;

            output_data[output_idx] = input_data[input_idx];
            output_data[output_idx + 1] = input_data[input_idx + 1];
            output_data[output_idx + 2] = input_data[input_idx + 2];

            if (channels >= 4)
            {
                output_data[output_idx + 3] = input_data[input_idx + 3];
            }
        }
    }

    if (!write_image_data(output_filename, output_data, new_width, new_height))
    {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image %s\n", output_filename);
        free(input_data);
        free(output_data);
        return 0;
    }

    free(input_data);
    free(output_data);

    printf("Image tournée de 90° sauvegardée : %s (%dx%d -> %dx%d)\n",
           output_filename, width, height, new_width, new_height);

    return 1;
}

int scale_crop(const char *input_file, const char *output_file, int center_x, int center_y, int crop_width, int crop_height)
{
    unsigned char *data_in = NULL;
    int width_in, height_in, channel_count;

    if (!read_image_data(input_file, &data_in, &width_in, &height_in, &channel_count))
    {
        printf("Erreur lors de la lecture de l'image.\n");
        return 0;
    }

    unsigned char *data_out = malloc(crop_width * crop_height * channel_count);
    if (!data_out)
    {
        printf("Erreur d'allocation mémoire.\n");
        free(data_in);
        return 0;
    }

    int x_start = center_x - crop_width / 2;
    int y_start = center_y - crop_height / 2;

    for (int y = 0; y < crop_height; y++)
    {
        for (int x = 0; x < crop_width; x++)
        {
            int src_x = x_start + x;
            int src_y = (y_start + y);

            for (int c = 0; c < channel_count; c++)
            {
                if (src_x >= 0 && src_x < width_in && src_y >= 0 && src_y < height_in)
                {
                    data_out[(y * crop_width + x) * channel_count + c] = data_in[(src_y * width_in + src_x) * channel_count + c];
                }
                else
                {
                    data_out[(y * crop_width + x) * channel_count + c] = 0;
                }
            }
        }
    }

    if (!write_image_data(output_file, data_out, crop_width, crop_height))
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

void min_component(char *filename, char component)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    if (n < 3)
    {
        fprintf(stderr, "L'image doit avoir au moins 3 canaux (RGB)\n");
        free(data);
        return;
    }

    int min_value = 255;
    int min_x = 0, min_y = 0;
    int channel_offset;

    switch (component)
    {
    case 'R':
    case 'r':
        channel_offset = 0;
        break;
    case 'G':
    case 'g':
        channel_offset = 1;
        break;
    case 'B':
    case 'b':
        channel_offset = 2;
        break;
    default:
        fprintf(stderr, "Composant invalide. Utilisez R, G ou B\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_index = (y * width + x) * n + channel_offset;
            unsigned char current_value = data[pixel_index];

            if (current_value < min_value)
            {
                min_value = current_value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n",
           (component >= 'a' && component <= 'z') ? component - 32 : component,
           min_x, min_y, min_value);

    free(data);
}

void max_component(char *filename, char component)
{
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    if (!read_image_data(filename, &data, &width, &height, &n))
    {
        fprintf(stderr, "Impossible de lire l'image %s\n", filename);
        return;
    }

    if (n < 3)
    {
        fprintf(stderr, "L'image doit avoir au moins 3 canaux (RGB)\n");
        free(data);
        return;
    }

    int max_value = -1;
    int max_x = 0, max_y = 0;
    int channel_offset;

    switch (component)
    {
    case 'R':
    case 'r':
        channel_offset = 0;
        break;
    case 'G':
    case 'g':
        channel_offset = 1;
        break;
    case 'B':
    case 'b':
        channel_offset = 2;
        break;
    default:
        fprintf(stderr, "Composant invalide. Utilisez R, V ou B\n");
        free(data);
        return;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_index = (y * width + x) * n + channel_offset;
            unsigned char current_value = data[pixel_index];

            if ((int)current_value > max_value)
            {
                max_value = (int)current_value;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n",
           (component >= 'a' && component <= 'z') ? component - 32 : component,
           max_x, max_y, max_value);

    free(data);
}

int rotate_acw(const char *input_filename, const char *output_filename)
{
    unsigned char *input_data = NULL;
    unsigned char *output_data = NULL;
    int width, height, channels;
    int new_width, new_height;
    int x, y, input_idx, output_idx;
    int new_x, new_y;

    if (!read_image_data(input_filename, &input_data, &width, &height, &channels))
    {
        fprintf(stderr, "Erreur : Impossible de lire l'image %s\n", input_filename);
        return 0;
    }

    if (channels < 3)
    {
        fprintf(stderr, "Erreur : L'image doit avoir au moins 3 canaux\n");
        free(input_data);
        return 0;
    }

    new_width = height;
    new_height = width;

    output_data = (unsigned char *)malloc(new_width * new_height * channels);
    if (output_data == NULL)
    {
        fprintf(stderr, "Erreur : Allocation mémoire échouée\n");
        free(input_data);
        return 0;
    }

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            input_idx = (y * width + x) * channels;

            new_x = y;
            new_y = width - 1 - x;

            output_idx = (new_y * new_width + new_x) * channels;

            output_data[output_idx] = input_data[input_idx];
            output_data[output_idx + 1] = input_data[input_idx + 1];
            output_data[output_idx + 2] = input_data[input_idx + 2];

            if (channels >= 4)
            {
                output_data[output_idx + 3] = input_data[input_idx + 3];
            }
        }
    }

    if (!write_image_data(output_filename, output_data, new_width, new_height))
    {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image %s\n", output_filename);
        free(input_data);
        free(output_data);
        return 0;
    }

    free(input_data);
    free(output_data);

    printf("Image tournée de 90° anti-horaire sauvegardée : %s (%dx%d -> %dx%d)\n",
           output_filename, width, height, new_width, new_height);

    return 1;
}

int mirror_horizontal(const char *input_filename, const char *output_filename)
{
    unsigned char *input_data = NULL;
    unsigned char *output_data = NULL;
    int width, height, channels;
    int x, y, input_idx, output_idx;
    int mirrored_x;

    if (!read_image_data(input_filename, &input_data, &width, &height, &channels))
    {
        fprintf(stderr, "Erreur : Impossible de lire l'image %s\n", input_filename);
        return 0;
    }

    if (channels < 3)
    {
        fprintf(stderr, "Erreur : L'image doit avoir au moins 3 canaux\n");
        free(input_data);
        return 0;
    }

    output_data = (unsigned char *)malloc(width * height * channels);
    if (output_data == NULL)
    {
        fprintf(stderr, "Erreur : Allocation mémoire échouée\n");
        free(input_data);
        return 0;
    }

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            input_idx = (y * width + x) * channels;

            mirrored_x = width - 1 - x;

            output_idx = (y * width + mirrored_x) * channels;

            output_data[output_idx] = input_data[input_idx];
            output_data[output_idx + 1] = input_data[input_idx + 1];
            output_data[output_idx + 2] = input_data[input_idx + 2];

            if (channels >= 4)
            {
                output_data[output_idx + 3] = input_data[input_idx + 3];
            }
        }
    }

    if (!write_image_data(output_filename, output_data, width, height))
    {
        fprintf(stderr, "Erreur : Impossible d'écrire l'image %s\n", output_filename);
        free(input_data);
        free(output_data);
        return 0;
    }

    free(input_data);
    free(output_data);

    printf("Image miroir horizontal sauvegardée : %s (%dx%d)\n",
           output_filename, width, height);

    return 1;
}

void scale_nearest(const char *inputFilename, const char *outputFilename, double scale)
{
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(inputFilename, &data, &width, &height, &channel_count))
    {
        fprintf(stderr, "Erreur : Impossible de lire l'image %s\n", inputFilename);
        return;
    }

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);

    if (new_width > MAX_WIDTH || new_height > MAX_HEIGHT)
    {
        fprintf(stderr, "Erreur : image redimensionnée trop grande (max %dx%d)\n", MAX_WIDTH, MAX_HEIGHT);
        free(data);
        return;
    }

    unsigned char *new_data = malloc(new_width * new_height * channel_count);
    if (!new_data)
    {
        printf("Erreur d'allocation mémoire.\n");
        free(data);
        return;
    }

    for (int y = 0; y < new_height; y++)
    {
        for (int x = 0; x < new_width; x++)
        {
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);

            if (src_x >= width)
                src_x = width - 1;
            if (src_y >= height)
                src_y = height - 1;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(y * new_width + x) * channel_count + c] =
                    data[(src_y * width + src_x) * channel_count + c];
            }
        }
    }

    write_image_data(outputFilename, new_data, new_width, new_height);
    free(data);
}
