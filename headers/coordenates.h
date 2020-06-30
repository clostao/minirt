#ifndef COORDENATES_H
 #define COORDENATES_H
 #include "math_structures.h"
 #include "figures.h"
 #include "program_management.h"
 t_vector3  get_point_lambda_ray(t_ray ray, double lambda);
 t_vector3  vector_between_two_points(t_vector3 v, t_vector3 w);
 t_vector3  unitary_vector(t_vector3 v);
 double     vector_module(t_vector3 v);
 double     angle_between_vectors(t_vector3 v, t_vector3 w);
 double     point_vector_product(t_vector3 v, t_vector3 w);
#endif