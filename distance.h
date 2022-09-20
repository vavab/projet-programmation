/**
 * @file distance.h
 * @author Valentine Baumann ()
 * @brief Calcule les distances entre deux arbres
 * en utilisant la formule de haversine.
 * @version 0.1
 * @date 2021-05-24
 * 
 * 
 */
#ifndef DISTANCE_H
#define DISTANCE_H
#include <math.h>
#include <stdio.h>
#define PI 3.14

/**
 * @brief Convertit l'entier x donné en degrés
 * en radians.
 * 
 * @param x 
 * @return int 
 */
long double convert_rad(long double x) ;

/**
 * @brief Calcule la distance en mètres entre deux points a et b
 * de coordonnées respectives (lat_a, long_a) et 
 * (lat_b, long_b).
 * 
 * @param lat_a 
 * @param lat_b 
 * @param long_a 
 * @param long_b 
 * @return long double  
 */
int calcul_distance(long double lat_a, long double lat_b, long double long_a, long double long_b) ;



#endif