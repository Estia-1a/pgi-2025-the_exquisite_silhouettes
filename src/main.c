#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv)
{
  /*To use debug mode:
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration;
  parse_arguments(argc, argv, &configuration);
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld
   */
  if (strncmp(configuration.command, "helloworld", 10) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  else if (strncmp(configuration.command, "dimension", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    dimension(configuration.filenames[0]);
  }

  else if (strncmp(configuration.command, "first_pixel", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
  }
  else if (strncmp(configuration.command, "tenth_pixel", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    tenth_pixel(configuration.filenames[0]);
  }
  else if (strncmp(configuration.command, "second_line", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    second_line(configuration.filenames[0], 1, 0);
  }
  else if (strncmp(configuration.command, "print_pixel", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    print_pixel(configuration.filenames[0], 45, 500);
  }
  else if (strncmp(configuration.command, "max_pixel", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    max_pixel(configuration.filenames[0]);
  }

  else if (strncmp(configuration.command, "min_pixel", 3) == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    min_pixel(configuration.filenames[0]);
  }

  else if (strcmp(configuration.command, "color_red") == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_red(configuration.filenames[0]);
  }

  else if (strcmp(configuration.command, "color_green") == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_green(configuration.filenames[0]);
  }
  else if (strcmp(configuration.command, "color_blue") == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_blue(configuration.filenames[0]);
  }

  else if (strcmp(configuration.command, "color_gray") == 0)
  {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_gray(configuration.filenames[0]);
  }

  else if (strcmp(configuration.command, "inverser") == 0)
  {

    /* helloworld() function is defined in feature.h and implemented in feature.c */
    inverser(configuration.filenames[0], "image_out.bmp");
  }

  else if (strcmp(configuration.command, "color_gray_luminance") == 0)
  {

    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_gray_luminance(configuration.filenames[0], "image_out.bmp");
  }

  else if (strcmp(configuration.command, "color_desaturate") == 0)
  {

    /* helloworld() function is defined in feature.h and implemented in feature.c */
    color_desaturate(configuration.filenames[0], "image_out.bmp");
  }

  else if (strcmp(configuration.command, "scale_bilinear") == 0)
  {

    /* helloworld() function is defined in feature.h and implemented in feature.c */
    double scale = atof(configuration.arguments[0]);
    scale_bilinear(configuration.filenames[0], "image_out.bmp", scale);
  }
  /*
   * TO COMPLETE
   */

  else if (strcmp(configuration.command, "rotate_cw") == 0)
  {
    rotate_cw(configuration.filenames[0], "image_out.bmp");
  }

  return 0;
}
