#ifndef MINIRT_H
#define MINIRT_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI  3.1415926535

// struct for image info
typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

// struct for aplication window
typedef struct  s_vars {
        void    *mlx;
        void    *win;
        t_data  *img;
}               t_vars;

int         close(int keycode, t_vars *vars);
void        my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif