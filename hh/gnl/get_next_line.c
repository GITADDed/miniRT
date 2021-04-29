# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

size_t		ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

void	set_last(char **last, char *temp, int flag)
{
	char	*fre;

	if (flag)
	{
		*temp = '\0';
		fre = *last;
		*last = ft_strdup(++temp);
		free(fre);
	}
	else
	{
		fre = *last;
		*last = NULL;
		free(fre);
	}
}

char	*checker(char *last, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (last)
	{
		if ((tmp = ft_strchr(last, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(last);
			ft_strcpy(last, ++tmp);
		}
		else
			*line = ft_strdup(last);
	}
	else
		*line = ft_strdup("");
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*last;
	char		*temp;
	int			r_bytes;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = NULL;
	temp = checker(last, line);
	while (!temp && (r_bytes = read(fd, buff, BUFFER_SIZE)))
	{
		buff[r_bytes] = '\0';
		if ((temp = ft_strchr(buff, '\n')))
			set_last(&last, temp, 1);
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	if (temp)
		return (1);
	set_last(&last, temp, 0);
	return (0);
}

