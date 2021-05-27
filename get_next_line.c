#include "get_next_line.h"

static int	ft_free(char **line)
{
	if (*line != NULL)
		free(*line);
	*line = NULL;
	return (-1);
}

static int	ft_error(int rd, char **rm)
{
	if (rd < 0)
	{
		ft_free(rm);
		return (-1);
	}
	return (0);
}

static int	ft_string(char **rm, char **line)
{
	if (ft_strzchr(*rm, '\0', 0))
	{
		*line = ft_strdup(*rm);
		if (!*line)
			return (-1);
		ft_free(rm);
	}
	return (0);
}

static int	ft_remain(char **rm, char **line, int rd)
{
	char	*n;
	char	*tmp;

	if (ft_error(rd, rm))
		return (-1);
	if (!rd && !*rm)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((n = ft_strzchr(*rm, '\n', 0)))
	{
		*n = '\0';
		*line = ft_strdup(*rm);
		tmp = ft_strdup(++n);
		if (!*line || !tmp)
			return (-1);
		ft_free(rm);
		*rm = tmp;
		return (1);
	}
	return (ft_string(rm, line));
}

int			get_next_line(int fd, char **line)
{
	int			rd;
	char		*bf;
	char		*tmp;
	static char	*rm = NULL;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (rd = 0) ||
			!(bf = (char*)malloc(BUFFER_SIZE + 1)) || read(fd, 0, 0) < 0)
		return (-1);
	if (!ft_strzchr(rm, '\n', 1))
		while ((rd = read(fd, bf, BUFFER_SIZE)))
		{
			bf[rd] = '\0';
			if (rm)
			{
				tmp = ft_strjoin(rm, bf);
				ft_free(&rm);
				rm = tmp;
			}
			else
				rm = ft_strdup(bf);
			if (ft_strzchr(bf, '\n', 0))
				break ;
		}
	ft_free(&bf);
	return (ft_remain(&rm, line, rd));
}
