#include "outils.h"

int copie_fichier(char *path_in, char *path_out) {

    FILE* f_in ; 
    FILE* f_out ; 
    char buffer[SIZE] ; 
    int a ; 
  
    if ((f_in = fopen(path_in, "r")) == NULL) 
    { 
        perror("open f_in") ;
        return 1 ; 
    } 
  
    if ((f_out = fopen(path_out, "w")) == NULL) 
    { 
        perror("open f_out") ;
        fclose(f_in) ; 
        return 1 ; 
    } 
  
    while ((a = fread(buffer, 1, SIZE, f_in)) != 0) 
        fwrite(buffer, 1, a, f_out) ; 
  
    fclose(f_out) ; 
    fclose(f_in) ; 
  
    return 0 ; 
}

int recup_nb_lig(char *path) {
    int nb_lig = 0 ;

    FILE *f ;
    char c ;

    if ((f = fopen(path, "r")) == NULL) 
    { 
        fprintf(stderr, "fopen dans recup_nb_lig() a échoué.\n") ;
        perror("fopen") ;
        return 1 ; 
    } 

    while((c = fgetc(f)) != EOF)
    {
        if(c=='\n')
        {
            nb_lig++ ;
        }
    }
    fclose(f) ;
    return nb_lig ;
}