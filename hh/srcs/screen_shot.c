#include "minirt.h"

unsigned int	my_mlx_pixel_take(t_data *data, int x, int y)
{
	return (*(unsigned int*)(data->addr + (y * data->line_length
	+ x * (data->bits_per_pixel / 8))));
}

static void		screenshot_norm_two(int fd, int all_pix, int zero, int size)
{
	write(fd, &zero, 4);
	write(fd, &size, 4);
	all_pix = 1000;
	write(fd, &all_pix, 4);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

static void		screenshot_norm_one(int fd)
{
	short	plane;

	plane = 1;
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void			fill_screen(int fd, t_all *all)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < all->scene.view.rh)
	{
		j = 0;
		while (j < all->scene.view.rw)
		{
			color = my_mlx_pixel_take(&(all->img), j,
							all->scene.view.rh - 1 - i);
			write(fd, &color, 4);
			j++;
		}
		i++;
	}
}

void			screenshot(t_all *all)
{
	int				fd;
	int				all_pix;
	int				zero;
	int				pos_pix;
	int				size;

	fd = open("screen.bmp", O_CREAT | O_WRONLY, 0777);
	all_pix = all->scene.view.rw * all->scene.view.rh * 4 + 54;
	zero = 0;
	pos_pix = 54;
	size = all->scene.view.rw * all->scene.view.rh;
	write(fd, "BM", 2);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pix, 4);
	pos_pix = 40;
	write(fd, &pos_pix, 4);
	write(fd, &all->scene.view.rw, 4);
	write(fd, &all->scene.view.rh, 4);
	screenshot_norm_one(fd);
	screenshot_norm_two(fd, all_pix, zero, size);
	fill_screen(fd, all);
}
