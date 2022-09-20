/**
 * @file kruskal.h
 * @author Valentine Baumann ()
 * @brief Implémente l'algorithme de Kruskal et ses fonctions sous-jacentes.
 * @version 0.1
 * @date 2021-05-30
 * 
 * 
 */
#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "graphe.h"

/**
 * @brief Structure représentant un sommet.
 * 
 */
typedef struct sommet {
    int num_sommet ;
    int classe ;

} sommet ;

/**
 * @brief Structure représentant une arête 
 * (2 sommets u et v)
 * (pondération de l'arête pond)
 * 
 */
typedef struct arete {
    sommet u,v ;
    int pond ;
    
} arete ;

/**
 * @brief Structure représentant une liste d'arêtes.
 * (un pointeur vers arete)
 * (le nombre d'aretes dans la liste)
 * 
 */
typedef struct arete_liste {
    arete *a ;
    int nb_arete ;
} arete_liste ;


/**
 * @brief Trie les arêtes par poids croissant.
 * 
 * @return int 
 */
int trier() ;

/**
 * @brief Calcule le poids du graphe minimisé.
 * 
 * @return int 
 */
int calcul_cout(arete_liste new_liste) ;

/**
 * @brief Implémente l'algorithme de Kruskal.
 * 
 * @param G 
 * @return arete_liste (liste des arêtes du graphe minimisé) 
 */
arete_liste kruskal(int nb_lig, graph G) ;



#endif