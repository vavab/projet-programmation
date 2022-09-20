#include "distance.h"


long double convert_rad(long double x) {
    x = x*PI/ 180 ;
    return x ;
}

int calcul_distance(long double lat_a, long double lat_b, long double long_a, long double long_b) {
    
    lat_a = convert_rad(lat_a) ;
    lat_b = convert_rad(lat_b) ;
    long_a = convert_rad(long_a) ;
    long_b = convert_rad(long_b) ;

    long double a ;
    a = sin((lat_b-lat_a)/2)*sin((lat_b-lat_a)/2)
    + cos(lat_a)*cos(lat_b)*sin((long_b - long_a)/2)*sin((long_b - long_a)/2) ;

    int d ;
    d = 6371000*2*atan((sqrt(a))/(sqrt(1-a))) ;


    return d ;


}