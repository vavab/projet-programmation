#include "id.h"

int extraire_id(char *path, arbre_t *tab) {
    
    FILE *f ;
    if((f = fopen(path, "r")) == NULL)
    {
        fprintf(stderr, "fopen dans extraire_id a échoué.\n") ;
        perror("fopen") ;
        return -1 ;
    }

    char * unused_buf = (char *) malloc(MAXLENGTH) ;
    //on lit la première ligne du fichier (inutile car spécifie les champs)
    fgets(unused_buf, MAXLENGTH, f) ;
    free(unused_buf) ;

    char *line ;
    if((line = (char*) malloc(MAXLENGTH)) == NULL)
    {
        perror("malloc") ;
        return 1 ;
    }
    
    char *token ;
    int data ;
    int count = 0 ;

    while(!feof(f)) 
    {
        //lit les lignes à partir de la 2ème jusqu'à la fin du fichier
        fgets(line, MAXLENGTH, f) ; 
        //récupère le premier token (1ere colonne) et le stocke dans token
        token = strtok(line, ";") ; 
        data = atoi(token) ;

        (tab[count]).id_base = data ;

        count++ ;
    }

    free(line) ;

    fclose(f) ;
    return 0 ; 
    
}
