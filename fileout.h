/**
 * @file fichier_out.h
 * @author Valentine Baumann ()
 * @brief Ouvre le fichier de sortie et y écrit :
 * La longueur totale de corde nécessaire pour relier tous les arbres entre eux et
 * la liste des paires d'arbres à relier par une corde. 
 * (on pourra utiliser l'identifiant des arbres de la base
 * de données).
 * @version 0.1
 * @date 2021-05-25
 * 
 * 
 */
#ifndef FILEOUT_H
#define FILEOUT_H
#include "kruskal.h"
#include <stdio.h>

/**
 * @brief Écrit dans le fichier de sortie le cout total et les arêtes utilisées.
 */
int ecrit_out(char *path, arete_liste mst) ;


#endif
