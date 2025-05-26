#include <estia-image.h>
#include <stdio.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 *
 */

pixelRGB *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y)
{
    if (data == NULL || x >= width || y >= height)
    {
        return NULL;
    }
    unsigned int index = (y * width + x) * n;
    static pixelRGB pixel;
    pixel.R = data[index];
    pixel.V = data[index + 1];
    pixel.B = data[index + 2];

    return &pixel;
}
