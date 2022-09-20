#include "fileout.h"

int ecrit_out(char *path, arete_liste mst) {
    
    int cout = calcul_cout(mst) ;

    FILE *f ;
    if((f = fopen(path, "w")) == NULL)
    {
        fprintf(stderr, "fopen dans ecrit_out a échoué.\n") ;
        perror("fopen") ;
        return -1 ;
    }

    fprintf(f, "\t RÉSULTATS DU PROGRAMME ARBRES DE PARIS\n") ;
    fprintf(f, "\t ======================================\n\n") ;

    fprintf(f, "Longueur de corde nécessaire pour relier tous les arbres : %d m .\n", cout) ;
    fprintf(f, "---------------------------------------------------------\n") ;
    fprintf(f, "Couples d'arbres (identifiants id_base) reliés :  \n") ;
    fprintf(f, "-----------------------------------------------\n") ;

    for(int i=1 ; i<mst.nb_arete+1 ; i++)
    {
        fprintf(f, "Arête %d : arbre n°%d - arbre n°%d \n", i, mst.a[i].u.num_sommet, mst.a[i].v.num_sommet) ;
    }

    return 0 ;
    

}
