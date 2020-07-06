#ifndef CAMERA_TOOLS_H
 #define CAMERA_TOOLS_H
 #include "figures.h"
 #include "math_structures.h"
void    set_rotation_matrix_x_fixed(double matrix[3][3], double angle);
void    set_rotation_matrix_y_fixed(double matrix[3][3], double angle);
void    set_rotation_matrix_z_fixed(double matrix[3][3], double angle);
t_vector3   matrix_product_vector(double matrix[3][3], t_vector3 v);
void    matrices_product(double a[3][3], double b[3][3], double result[3][3]);
t_vector3 get_pixel_from_screen(t_base base, short x, short y, t_scene scene);
#endif