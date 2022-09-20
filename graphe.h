/**
 * @file graphe.h
 * @author Valentine Baumann ()
 * @brief Crée le graphe en mémoire et associe des poids aux arrêtes.
 * @version 0.1
 * @date 2021-05-28
 * 
 * 
 */
#ifndef GRAPHE_H
#define GRAPHE_H
#include "distance.h"
#include "structure.h"

typedef struct graph {
    int **pond ;
    int *id_arbre ;
} graph ;

/**
 * @brief Alloue le graphe en mémoire.
 * 
 * @param nb_lig 
 * @return long double** 
 */
graph init_graph(int nb_lig) ;

/**
 * @brief Remplit le graphe en "reliant" les sommets.
 * 
 * @param nb_lig 
 * @param G 
 * @param list 
 * @return int 
 */
int fill_graph(int nb_lig, graph G, arbre_t *tab) ;

#endif