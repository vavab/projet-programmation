/**
 * @file id.h
 * @author Valentine Baumann ()
 * @brief Récupère les identifiants des arbres 
 * dans le fichier CSV.
 * Les identifiants se situent en première colonne de chaque ligne
 * du fichier.
 * @version 0.1
 * @date 2021-05-24
 * 
 * 
 */
#ifndef ID_H
#define ID_H
#define MAXLENGTH 1024

#include "structure.h"

/**
 * @brief Lit dans le fichier path tous les identifiants des arbres
 * et les stocke en mémoire dans une structure.
 * 
 * @param path 
 * @return int 
 */
int extraire_id(char *path, arbre_t *tab) ;


#endif