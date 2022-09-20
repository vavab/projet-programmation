/**
 * @file outils.h
 * @author Valentine Baumann ()
 * @brief Implémente des fonctions "outils" réutilisées dans le programme.
 * @version 0.1
 * @date 2021-05-28
 * 
 * 
 */
#ifndef OUTILS_H
#define OUTILS_H
#include <stdio.h>
#define SIZE 512

/**
 * @brief Réalise la copie d'un fichier path_in dans un fichier path_out.
 * 
 * @param path_in 
 * @param path_out 
 * @return int 
 */
int copie_fichier(char *path_in, char *path_out) ;

/**
 * @brief Ouvre le fichier path en lecture et compte le nombre de lignes.
 * 
 * @param path 
 * @return int 
 */
int recup_nb_lig(char *path) ;

#endif