#include "minirt.h"

int			esc(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int			press_red_cross(void)
{
	exit(0);
}

int			next_camera(int key_code, t_all *all)
{
	if (key_code == 49)
	{
		all->scene.cameras = all->scene.cameras->next;
		rendering(all, all->scene.cameras);
	}
	return (0);
}

void		init_mlx(t_all *all)
{
	if (all->screen != 1)
		all->mlx_win = mlx_new_window(all->mlx, all->scene.view.rw,
								all->scene.view.rh, "miniRT");
	all->img.img = mlx_new_image(all->mlx,
								all->scene.view.rw, all->scene.view.rh);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									&all->img.line_length, &all->img.endian);
}
