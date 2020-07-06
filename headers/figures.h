#ifndef FIGURES_H
 #define FIGURES_H
 t_collision plane_collision(t_plane plane, t_ray ray);
 t_collision cylinder_collision(t_cylinder cylinder, t_ray ray);
 t_collision sphere_collision(t_sphere sphere, t_ray ray);
 t_collision  get_collide_from_object(t_object_list *object, t_ray ray);
 t_vector3 set_vector3(double x, double y, double z);
 typedef struct s_vector3 {
	double	x;
	double	y;
	double	z;
 }				t_vector3;
 typedef struct s_color
 {
	short	red;
	short	green;
	short	blue;
	double	lightness;
 }				t_color;
 typedef struct s_collision
 {
	double		lambda;
	double		angle;
	t_color		color;
 }				t_collision;
 typedef struct s_cylinder
 {
	t_vector3	normal_vector;
	t_vector3	center;
	double		height;
	double		radius;
	t_color		color;
 }				t_cylinder;
 typedef struct s_plane
 {
	t_vector3	point;
	t_vector3	normal_vector;
	t_color		color;
 }				t_plane;
 typedef struct s_sphere
 {
	t_vector3	center;
	double		radius;
	t_color		color;
 }				t_sphere;
 typedef struct s_camera
 {
	t_vector3	center;
	t_vector3	orientation;
	int			fov;
 }				t_camera;
 typedef struct s_circle
 {
	t_vector3 	normal_vector;
	t_vector3 	center;
	double		radius;
	t_color		color;
 }				t_circle;
 
#endif