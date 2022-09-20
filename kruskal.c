#include "kruskal.h"



int trier(arete_liste A_liste) {
    //permet de stocker l'arete pour la déplacer dans la liste
    arete temporaire ;

    /**
     * On parcourt la liste des aretes pour déterminer l'arete
     * de poids minimal.
     * 
     */
    for(int i=1 ; i<A_liste.nb_arete ; i++)
    {
        for(int j=0 ; j<A_liste.nb_arete-1 ; j++)
        {
            if(A_liste.a[j].pond > A_liste.a[j+1].pond)
            {
                /**
                 * on conserve l'arete en "j" (poids plus fort)
                 */
                temporaire = A_liste.a[j] ;

                /**
                 * on place l'arete dont la pondération 
                 * est inférieure en "j"
                 */
                A_liste.a[j] = A_liste.a[j+1] ;

                //on place l'arete de poids plus fort en "j+1"
                A_liste.a[j+1] = temporaire ;
            }
        }
    }

    return 0 ;
}

arete_liste kruskal(int nb_lig, graph G) {
    
    arete_liste A_liste ;
    arete_liste new_liste ;
    

    /**
     * initialisation des listes d'arêtes :
     * A_liste et new_liste
     */
    A_liste.a = malloc(nb_lig*sizeof(arete)) ;
    new_liste.a = malloc(nb_lig*sizeof(arete)) ; 
    
    A_liste.nb_arete = 1 ;


    for(int i=1 ; i<nb_lig ; i++)
    {
        for(int j=0 ; j<i ; j++)
        {
            /**
             * on initialise la liste des aretes A_liste :
             * à chaque arete correspondent 2 numéros de sommet 
             * et une pondération.
             */
            A_liste.a[A_liste.nb_arete].u.num_sommet = G.id_arbre[i] ;
            A_liste.a[A_liste.nb_arete].v.num_sommet = G.id_arbre[j] ;

            A_liste.a[A_liste.nb_arete].pond = G.pond[i][j] ;

            A_liste.nb_arete++ ;
        }
    }



    trier(A_liste) ;

    int *classe = (int*)malloc(nb_lig*sizeof(int)) ;

    for(int i=1 ; i<nb_lig+1 ; i++)
    {
        classe[i] = i ;
    }

    new_liste.nb_arete = 0 ;

    /**
     * On compare les classes d'équivalence, si elles sont
     * différentes, on ajoute l'arete à l'ensemble new_list
     * et on fusionne les 2 classes d'équivalence.
     */
    for(int i=1 ; i<nb_lig+1 ; i++)
    {

        int no_arete = i*(i-1)/2 ;

        if(classe[i] != classe[i+1]) {

            if(i == nb_lig)
            {
                new_liste.a[new_liste.nb_arete].pond = A_liste.a[i].pond ;

                new_liste.a[new_liste.nb_arete].u.num_sommet = A_liste.a[i].u.num_sommet ;
                new_liste.a[new_liste.nb_arete].v.num_sommet = A_liste.a[i].v.num_sommet ;

            }
            else {

                int conserv_pond = A_liste.a[no_arete].pond ;

                int conserv_num_u = A_liste.a[no_arete].u.num_sommet ;
                int conserv_num_v = A_liste.a[no_arete].v.num_sommet ;

                int conserv_class_u = classe[i] ;
                
                new_liste.a[new_liste.nb_arete].pond = conserv_pond ;

                new_liste.a[new_liste.nb_arete].u.num_sommet = conserv_num_u ;
                new_liste.a[new_liste.nb_arete].v.num_sommet = conserv_num_v ;
                
                classe[i+1] = conserv_class_u ;
            }
                new_liste.nb_arete++ ;
            
        }
    }

    free(A_liste.a) ;
    free(classe) ;
    return new_liste ;
}

int calcul_cout(arete_liste new_liste) {
    int cout = 0 ;

    for(int i=0 ; i<new_liste.nb_arete ; i++)
    {
        cout = cout + new_liste.a[i].pond ;
    }

    return cout ;

}

