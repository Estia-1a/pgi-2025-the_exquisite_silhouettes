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

 void dimension(const char *fichier) {
    unsigned char* data = NULL;
    int w = 0, h = 0, c = 0;
    if (read_image_data(fichier, &data, &w, &h, &c) != 0) {
        printf("la dimension de l'image: %s est %d %d\n", fichier, w, h);
        free_image_data(data);
    } else {
        printf("Fail to open %s\n", fichier);
    }


 }
 
