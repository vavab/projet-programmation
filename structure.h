/**
 * @file structure.h
 * @author Valentine Baumann ()
 * @brief Construit les structures qui vont permettre 
 * de stocker les données extraites.
 * @version 0.1
 * @date 2021-05-24
 * 
 * 
 */
#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<math.h>
#include<unistd.h>

/**
 * @brief Structure qui donne les caractéristiques d'un arbre.
 * 
 */
typedef struct arbre_t {
    int id_base ;
    long double geo_lat ;
    long double geo_long ;
} arbre_t ;

/**
 * @brief Liste d'arbres.
 * 
 */
typedef struct list_t {
    arbre_t *tab ;
} list_t ;

/**
 * @brief Crée les structures qui vont stocker les données en mémoire.
 * 
 * @return list_t* 
 */
arbre_t *init_struct(int nb_lig) ;

/**
 * @brief Libère la mémoire allouée pour les structures.
 * 
 * @return int
 * 
 */
int liberer_struct(arbre_t *tab) ;

#endif

