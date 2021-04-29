/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaedric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 04:00:58 by bdaedric          #+#    #+#             */
/*   Updated: 2021/03/14 04:01:00 by bdaedric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parser(char **line, t_scene *scene)
{
	char	*tmp;

	tmp = *line;
	if (*tmp == 'R')
		set_screen(&tmp, scene);
	else if (*tmp == 'A')
	 	set_ambient_light(&tmp, scene);
	else if (*tmp == 'c' && !ft_isalpha(*(tmp + 1)))
	 	set_camera(&tmp, scene);
	else if (*tmp == 'l')
	 	set_light_source(&tmp, scene);
	else if (*tmp == 's' && *(tmp + 1) == 'p')
		set_sphere(&tmp, scene);
	else if (*tmp == 'p' && *(tmp + 1) == 'l')
		set_plane(&tmp, scene);
	else if (*tmp == 's' && *(tmp + 1) == 'q')
	 	set_square(&tmp, scene);
	else if (*tmp == 't' && *(tmp + 1) == 'r')
	 	set_triangle(&tmp, scene);
	else if (*tmp == 'c' && *(tmp + 1) == 'y')
			set_cylinder(&tmp, scene);
	else if (!*tmp)
		return ;
	else
		map_error("nothing needed found!");
	free (*line);
}
