#include "structure.h"

arbre_t *init_struct(int nb_lig) {
    
    //list_t *list ;

    arbre_t arbre_null ;
    arbre_null.id_base = 0 ;
    arbre_null.geo_lat = 0.0 ;
    arbre_null.geo_long = 0.0 ;

    arbre_t *tab ;
    if( ( tab = (arbre_t*)malloc(nb_lig*sizeof(arbre_t)) ) == NULL)
    {
        fprintf(stderr, "Malloc a échoué.\n") ;
        exit(1) ;
    }
    for(int i=0 ; i<nb_lig ; i++)
    {
        tab[i] = arbre_null ;
    }
       
    return tab;
}

int liberer_struct(arbre_t *tab) {
    free(tab) ;
    return 0 ;
}
