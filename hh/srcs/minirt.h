#ifndef MINIRT_H
# define MINIRT_H
# define EPSILON 0.00001
# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L<<0
# define NO_EVENT_MASK 0L
# define DESTROY_NOTIFY 17

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct			s_roots
{
	double				t_1;
	double				t_2;
}						t_roots;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef t_vector		t_color;

typedef struct			s_ray
{
	t_vector			orig;
	t_vector			dir;
}						t_ray;

typedef enum			e_obj_type
{
	T_SPHERE,
	T_CYLINDER,
	T_SQUARE,
	T_TRIANGLE,
	T_PLANE
}						t_obj_type;

typedef struct			s_quadratic
{
	double				a;
	double				b;
	double				c;
}						t_quadratic;

typedef struct			s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct			s_view
{
	int					rw;
	int					rh;
}						t_view;

typedef struct			s_plane
{
	t_obj_type			type;
	int					color;
	t_vector			orig;
	t_vector			vec_n;
}						t_plane;

typedef struct			s_sphere
{
	t_obj_type			type;
	int					color;
	t_vector			orig;
	double				diameter;
	t_vector			vec_n;
}						t_sphere;

typedef struct			s_triangle
{
	t_obj_type			type;
	int					color;
	t_vector			vertex_1;
	t_vector			vertex_2;
	t_vector			vertex_3;
	t_vector			point;
	t_vector			vec_n;
	double				s;
}						t_triangle;

typedef struct			s_cylinder
{
	t_obj_type			type;
	int					color;
	t_vector			vec_n;
	t_vector			surf_norm;
	t_vector			p_1;
	t_vector			oc;
	double				height;
	double				diameter;
	double				m;
	double				cur;
	double				t_1;
	double				t_2;
	double				n_dir;
	double				oc_norm;
}						t_cylinder;

typedef struct			s_square
{
	t_obj_type			type;
	int					color;
	t_vector			orig;
	t_vector			vec_n;
	double				side_size;
}						t_square;

typedef struct			s_light
{
	t_obj_type			type;
	int					color;
	t_vector			orig;
	double				intensity;
	struct s_light		*next;
}						t_light;

typedef struct			s_hit
{
	t_obj_type			type;
	t_vector			point;
	t_vector			norm;
	double				t;
	void				*figure;
}						t_hit;

typedef struct			s_camera
{
	t_vector			orig;
	t_vector			dir;
	double				fov;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_scene
{
	t_view				view;
	t_list				*objs;
	t_light				*lights;
	t_camera			*cameras;
	t_hit				closest;
	int					ambient_color;
	int					if_ambient;
	int					flag;
	int					col_det;
}						t_scene;

typedef struct			s_all
{
	t_scene				scene;
	t_data				img;
	void				*mlx;
	void				*mlx_win;
	int					x;
	int					y;
	int					screen;
}						t_all;

/*
** intersections with figures
*/
void					rendering(t_all *all, t_camera *camera);
int						sphere_intersection(t_scene *scene,
						t_sphere *cur_sphere, t_ray *ray);
int						test_intersection(t_scene *scene, t_ray *ray);
int						plane_intersection(t_scene *scene,
						t_plane *plane, t_ray *ray);
int						cylinder_intersection(t_scene *scene,
						t_cylinder *cyl, t_ray *ray);
int						triangle_intersection(t_scene *scene,
						t_triangle *tr, t_ray *ray);
int						square_intersection(t_scene *scene,
						t_square *square, t_ray *ray);
t_roots					solve_quadratic(t_quadratic *q);
int						get_color(t_hit *hit);
t_color					shade(t_scene *scene, t_color color);
void					init_normal(t_scene *scene);
t_color					int_to_color(int c);
int						color_to_int(t_color c);
void					init_tr_norm(t_triangle *triangle);

/*
** some useful formulas for vectors
*/
double					area_of_a_triangle(t_vector ver1,
						t_vector ver2, t_vector ver3);
t_vector				vec_mult(t_vector vec_1, t_vector vec_2);
t_vector				ray_set(int i, int j, t_scene *scene);
t_vector				vec_normalisation(t_vector v);
t_vector				vec_sub(t_vector vec_1, t_vector vec_2);
t_vector				vec_sum(t_vector vec_1, t_vector vec_2);
t_vector				vec_con_mult(double a, t_vector vec);
t_vector				cross(t_vector vec_1, t_vector vec_2);
double					check_scalar(t_vector v_1,
						t_vector v_norm, t_vector v_3);
double					length(t_vector v1);
double					scalar(t_vector v1, t_vector v2);
int						create_rgb(int r, int g, int b);
t_vector				vec_const_sum(double a, t_vector v);

/*
**parser functions
*/
void					check_norm(double n_x, double n_y, double n_z);
int						make_color(int r, int g, int b, double intensity);
char					*check_int_mini(char **line);
char					*ft_mini_check_double(char **line);
void					set_ambient_light(char **line, t_scene *scene);
void					set_camera(char **line, t_scene *scene);
void					set_plane(char **line, t_scene *scene);
void					parser(char **line, t_scene *scene);
void					set_screen(char **line, t_scene *scene);
void					set_light_source(char **line, t_scene *scene);
void					set_sphere(char **line, t_scene *scene);
void					set_square(char **line, t_scene *scene);
void					set_triangle(char **line, t_scene *scene);
void					set_cylinder(char **line, t_scene *scene);
double					ft_atod(const char *str, double num, int i);
int						rt_atoi(const char *str);

void					map_error(char *str);
t_vector				camera_to_world(t_vector ray, t_vector cam_dir);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					screenshot(t_all *all);
void					scaling(t_all *all);
void					init_mlx(t_all *all);
int						esc(int keycode);
int						press_red_cross(void);
int						next_camera(int key_code, t_all *all);
#endif
