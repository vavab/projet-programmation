/**
 * @file geo.h
 * @author Valentine Baumann ()
 * @brief Récupère les coordonnées géographiques des arbres 
 * dans le fichier CSV.
 * @version 0.1
 * @date 2021-05-24
 * 
 */
#ifndef GEO_H
#define GEO_H
#define MAXLENGTH 1024
#include "structure.h"

/**
 * @brief Lit dans le fichier path les coordonnées d'un arbre
 *  et les stocke en mémoire dans une structure.
 * 
 * @param path 
 * @param tab 
 * @return int 
 */
int extraire_geo(char *path, arbre_t *tab) ;

#endif