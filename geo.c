#include "geo.h"

int extraire_geo(char *path, arbre_t *tab) {
    
    FILE *f ;
    if((f = fopen(path, "r")) == NULL)
    {
        fprintf(stderr, "fopen dans extraire_geo a échoué.\n") ;
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
    char *token_lat ;
    char *token_long ;
    long double data_lat ;
    long double data_long ;

    int count = 0 ;
    while(!feof(f))
    {
        //on lit les lignes à partir de la 2ème jusqu'à la fin du fichier
        fgets(line, MAXLENGTH, f) ;

        //premier appel à strtok  
        token = strtok(line, ";") ;

        
        while(token != NULL)
        {
            //on ne conserve que le champ correspondant aux coordonnées
            if((token[0] == '4' && token[1] == '8' && token[2] == '.'))
            {

                //on sépare latitude et longitude
                token_lat = strtok(token, ",") ;
                sscanf(token_lat, "%Le", &data_lat) ;
                (tab[count]).geo_lat = data_lat ;
                
                token_long = strtok(NULL, ",") ;
                sscanf(token_long, "%Le", &data_long) ;
                (tab[count]).geo_long = data_long ;
                
            }

            //appels successifs
            token = strtok(NULL, ";") ;
        }

        count++ ;
    }

    free(line) ;
    fclose(f) ;
    return 0 ;

}
