/**
 * @file main.c
 * @author Valentine Baumann ()
 * @brief Main
 * @version 0.1
 * @date 2021-05-24
 * 
 * 
 */
#include "outils.h"
#include "id.h"
#include "geo.h"
#include "graphe.h"
#include "kruskal.h"
#include "fileout.h"
#include <getopt.h>


int main(int argc, char *argv[])
{

    int opt ;
    char *in ;
    char *out ;

/**
 * PARTIE GESTION DES ARGUMENTS------------------------------------------------
 * Récupère les paramètres en ligne de commande
 * de la forme : -i BASE_DE_DONNEE -o FICHIER_DE_SORTIE.
 * Affiche une erreur si les options ne sont pas suivies d'un argument
 * ou si le nombre d'arguments est inférieur à 2.
 * 
 */

    opterr = 0 ;
    if(argc < 2)
    {
        fprintf(stderr, "Le nombre d'arguments est insuffisant.\n") ;
        return 1 ;
    }
    while( (opt = getopt(argc, argv, "i:o:")) != -1 ) 
    {
        switch(opt)
        {
            case 'i' :
                in = optarg ;
                break ;
            case 'o' :
                out = optarg ;
                break ;
            case '?' :
                if(optopt == 'i' || optopt == 'o')
                {
                    fprintf(stderr, "L'option %c requiert un argument.\n", optopt) ;
                    return 1 ;
                }
        }
    }



/**
 * Récupération du nombre d'arbres(=nombre de lignes du fichier)---------------
 */

    int nb_lig = recup_nb_lig(in) ;

    printf("Fichier in : %s.\n", in) ;
    printf("Nombre de lignes du fichier source : %d.\n", nb_lig) ;
    printf("Fichier out : %s.\n", out) ;


/**
 * Initialisation des structures et récupération des données-------------------
 * Remplissage des structures
 */

    arbre_t *tab = init_struct(nb_lig) ;

    extraire_id(in, tab) ;
    extraire_geo(in, tab) ;

/**
 * Initialisation, remplissage du graphe-------------------------------------
 */

    graph G = init_graph(nb_lig) ;
    fill_graph(nb_lig, G, tab) ;

    liberer_struct(tab) ;
/**
 * Algorithme de Kruskal et écriture des résultats-----------------------------
 */

    arete_liste mst = kruskal(nb_lig, G) ;
    
    ecrit_out(out, mst) ;
    printf("Programme terminé. Consulter le fichier %s.\n", out) ;

    return 0 ;

}