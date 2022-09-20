#include "graphe.h"

graph init_graph(int nb_lig) {
    
    graph G ;

    if ((G.pond = malloc(nb_lig*sizeof(int*))) == NULL) {
        fprintf(stderr, "Malloc graphe a échoué.\n") ;
        exit(1) ;
    }
    
    for(int i=0 ; i<nb_lig ; i++)
    {
        if (((G.pond)[i] = malloc(nb_lig*sizeof(int))) == NULL) {
            fprintf(stderr, "Malloc graphe a échoué.\n") ;
            exit(1) ;
        }
    }

    if (((G.id_arbre) = malloc(nb_lig*sizeof(int))) == NULL) {
        fprintf(stderr, "Malloc graphe a échoué.\n") ;
        exit(1) ;
    }
    
    return G ;
}

int fill_graph(int nb_lig, graph G, arbre_t *tab) {
    
    long double lat_1, lat_2, long_1, long_2;

    //on parcourt les sommets "1" 
    for(int s1=0 ; s1<nb_lig ; s1++)
    {
        G.id_arbre[s1] = tab[s1].id_base ;
        //on parcourt les sommets "2"
        for(int s2=0 ; s2<nb_lig ; s2++)
        {
            lat_1 = (tab[s1]).geo_lat ;
            long_1 = (tab[s1]).geo_long ;
            lat_2 = (tab[s2]).geo_lat ;
            long_2 = (tab[s2]).geo_long ;
            //on construit le graphe en "reliant" chaque sommet à tous les autres
            (G.pond[s1])[s2] = calcul_distance(lat_1, lat_2, long_1, long_2);
        }
    }


    return 0 ;

    
}

