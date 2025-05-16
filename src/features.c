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


 void dimension(char *adresse);
 unsigned char *read_image_data=NULL;
 int largeur=0,hauteur=0,c=0;
 
 if (read_image_data(adresse,&w,&h,&c)){
     printf("dimension: %d, %d",w,h);
     else{
         fprintf(stderr,"nique ta photo ya une erreur sorry brother",adresse);
     }
 }
 if (data!=NULL){
     free(data);
 }
 
