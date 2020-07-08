#ifndef HEADERS_H
#define HEADERS_H
#include <math.h>
#include <strings.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
typedef struct s_object_list
{
  void *object;
  const char *type;
  struct s_object_list *next;
} t_object_list;
typedef struct s_vector3
{
  double x;
  double y;
  double z;
} t_vector3;
typedef struct s_color
{
  short red;
  short green;
  short blue;
  double lightness;
} t_color;
typedef struct s_light
{
  t_vector3 point;
  t_color color;
  double lightness;
} t_light;
typedef struct s_collision
{
  double lambda;
  double angle;
  t_color color;
} t_collision;
typedef struct s_cylinder
{
  t_vector3 normal_vector;
  t_vector3 center;
  double height;
  double radius;
  t_color color;
} t_cylinder;
typedef struct s_plane
{
  t_vector3 point;
  t_vector3 normal_vector;
  t_color color;
} t_plane;
typedef struct s_sphere
{
  t_vector3 center;
  double radius;
  t_color color;
} t_sphere;
typedef struct s_camera
{
  t_vector3 center;
  t_vector3 orientation;
  int fov;
} t_camera;
typedef struct s_circle
{
  t_vector3 normal_vector;
  t_vector3 center;
  double radius;
  t_color color;
} t_circle;

typedef struct s_screen
{
  int x;
  int y;
} t_screen;
typedef struct s_minilib
{
  short int actual_camera;
  void **images;
  void *session;
  void *window;
} t_minilib;
typedef struct s_scene
{
  t_object_list *lights;
  t_object_list *figures;
  t_light ambient_light;
  t_camera camera;
  t_screen screen;
  t_minilib minilib;
} t_scene;

typedef struct s_base
{
  t_vector3 i;
  t_vector3 j;
  t_vector3 k;
} t_base;

typedef struct s_solution
{
  double x1;
  double x2;
} t_solution;
typedef struct s_trinomial
{
  double c;
  double x;
  double x2;
} t_trinomial;
typedef struct  s_binomial
{
  double c;
  double x;
}               t_binomial;
typedef struct s_ray
{
  t_vector3 point;
  t_vector3 vector;
} t_ray;
t_collision plane_collision(t_plane plane, t_ray ray);
t_collision cylinder_collision(t_cylinder cylinder, t_ray ray);
t_collision sphere_collision(t_sphere sphere, t_ray ray);
t_collision get_collide_from_object(t_object_list *object, t_ray ray);
t_vector3 set_vector3(double x, double y, double z);
t_vector3 matrix_product_vector(double matrix[3][3], t_vector3 v);
void matrices_product(double a[3][3], double b[3][3], double result[3][3]);
t_vector3 get_pixel_from_screen(t_base base, short x, short y, t_scene scene);
t_collision calculate_closest_collision(t_ray ray, t_scene scene);
t_color apply_lightness_to_color(t_color color, double lightness);
double point_incident_lightness(t_object_list *figures, t_ray light_directed_ray);
t_ray get_collision_ray_from_light(t_light light, t_vector3 collision_point);
t_color black_color();
t_color calculate_color_from_vector(t_ray ray, t_scene scene);
t_color add_color(t_color acccolor, t_color light_color, t_collision collision);
t_vector3 get_point_lambda_ray(t_ray ray, double lambda);
t_vector3 vector_between_two_points(t_vector3 v, t_vector3 w);
t_vector3 unitary_vector(t_vector3 v);
double vector_module(t_vector3 v);
double angle_between_vectors(t_vector3 v, t_vector3 w);
double point_vector_product(t_vector3 v, t_vector3 w);
t_trinomial binomial_square(t_binomial bin);
t_binomial get_binomial(double c, double x);
t_binomial binomial_sum(int argc, ...);
t_solution second_grade_equation_solver(t_trinomial trin);
t_trinomial trinomial_sum(int argc, ...);
t_binomial binomial_multiplied_sum(t_binomial x, t_binomial y, int y_multiplier);
t_binomial get_binomial_from_cylinder_coords(t_binomial x, double x_multiplier, t_binomial y, double y_multiplier);
t_binomial multiply_binomial(t_binomial x, double multiplier);
t_trinomial get_trinomial_from_binomial_squared_sum(t_binomial bin1, t_binomial bin2, t_binomial bin3);
double get_lowest_positive_value(int argc, ...);
t_vector3 cross_vector_product(t_vector3 v, t_vector3 w);
t_base calculate_camera_base(t_vector3 z_vector);
double get_lowest_positive_value(int argc, ...);
double get_lowest_positive_solution(t_solution solution);
void   print_on_screen(unsigned int i, unsigned int j, t_scene scene, t_color color);
#endif