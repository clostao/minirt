#ifndef PROGRAM_MANAGEMENT_H
 #define PROGRAM_MANAGEMENT_H
 #include "figures.h"
 typedef struct s_ray
 {
    t_vector3 point;
    t_vector3 vector;
 }              t_ray;
 
 typedef struct            s_object_list
 {
    void                   *object;
    const char             *type;
    struct s_object_list   *next;
 }                         t_object_list;
 typedef struct   s_light
 {
   t_vector3      point;
   t_color        color;
   double         lightness;
 }                t_light;
#endif