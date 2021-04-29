#include "minirt.h"

int			create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_vector	cross(t_vector vec_1, t_vector vec_2)
{
	t_vector		result;

	result.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	result.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	result.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
	return (result);
}

double		scalar(t_vector v1, t_vector v2)
{
	double			res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

double		ft_atod(const char *str, double num, int i)
{
	int				flags[2];

	flags[0] = 0;
	flags[1] = 0;
	if (*str == '-')
	{
		str++;
		flags[0] = 1;
	}
	while ((*str >= '0' && *str <= '9') || *str == '.')
	{
		if (*str == '.')
		{
			flags[1] = 1;
			str++;
		}
		if (flags[1])
			i++;
		num = (num * 10) + (*str - '0');
		str++;
	}
	num /= pow(10, i);
	if (flags[0])
		num = -num;
	return (num);
}

char		*check_int_mini(char **line)
{
	int			flag;
	char		*str;

	flag = 0;
	while (**line == ' ')
		(*line)++;
	str = *line;
	if (**line == ',')
		map_error("invalid value!");
	while (**line != ',' && **line != ' ' && **line != '\0')
	{
		if (!ft_isdigit(**line) && **line != '+' && **line != '-')
			map_error("invalid value!");
		else if ((**line == '+' || **line == '-') && flag)
			map_error("invalid value!");
		if ((**line == '+' || **line == '-'))
			flag = 1;
		(*line)++;
	}
	if (**line == ',')
		(*line)++;
	if (!*line)
		map_error("!not enough arguments!");
	return (str);
}
