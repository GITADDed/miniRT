#include "minirt.h"

void		helper(int fd, char *line, t_all *all)
{
	while (get_next_line(fd, &line))
		parser(&line, &all->scene);
	parser(&line, &all->scene);
	if (!all->scene.view.rh ||!all->scene.view.rw)
		map_error("Screen settings not found");
	if (!all->scene.if_ambient)
		map_error("Ambient light found!");
	all->mlx = mlx_init();
	scaling(all);
	
	init_mlx(all);
	rendering(all, all->scene.cameras);
}

void		arguments_validation(int fd, int argc, char *line)
{
	char	*check_line;

	check_line = NULL;
	if (fd < 0)
		map_error("no such file!");
	if (argc < 2)
		map_error("not enough argument");
	else if (argc == 2)
	{
		check_line = ft_strchr(line, '.');
		check_line++;
		if (*check_line != 'r' && *check_line + 1 != 't')
			map_error("wrong file for scene!");
	}
	else if (argc > 3)
		map_error("too many arguments!");
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_all	all;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	arguments_validation(fd, argc, argv[1]);
	ft_memset(&all, '\0', sizeof(t_all));
	if (argc == 3 && argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
		&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e' && argv[2][6] == '\0')
		all.screen = 1;
	else if (argv[2])
		map_error("wrong flag");
	helper(fd, line, &all);
	mlx_key_hook(all.mlx_win, next_camera, &all);
	mlx_hook(all.mlx_win, KEY_PRESS, KEY_PRESS_MASK, esc, &all);
	mlx_hook(all.mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, press_red_cross, &all);
	mlx_loop(all.mlx);
	close(fd);
	return (0);
}
