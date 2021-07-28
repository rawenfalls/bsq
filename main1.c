#include "ft_list.h"

int	check_fl(t_list br)
{
	int	i;
	int	fd;
	int	c;

	i = -1;
	fd = open(br.fn, O_RDONLY);
	while (read(fd, &c, 1))
	{
		i++;
		if (c == '\n')
			break ;
	}
	close(fd);
	return (i);
}

t_list	check_first_string(t_list br, int c, int num, int j)
{
	int		fd;
	int		i;

	i = check_fl(br);
	fd = open(br.fn, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		if ((c >= '0') && (c <= '9') && (j < i - 3))
			num = num * 10 + c - 48;
		if (j == (i - 3))
			br.full_stop = c;
		if (j == (i - 2))
			br.o = c;
		if (j == (i - 1))
			br.x = c;
		j++;
	}
	close (fd);
	if (num == 0 || num + 1 != br.strock || i - 3 == 0 || br.x == br.o
		|| br.x == br.full_stop || br.full_stop == br.o)
		br.error = 1;
	return (br);
}

int	riad_scuare(char **array, int pos_i, int pos_j, t_list br)
{
	int	i;
	int	e;
	int	q;

	if (array[pos_i][pos_j] == br.o)
		return (0);
	if (br.strock == 2)
		return (1);
	i = 1;
	while ((pos_i + i < br.strock) && (pos_j + i < br.strin))
	{
		e = pos_i - 1;
		q = pos_j - 1;
		while (++e < pos_i + i)
			if (array[e][pos_j + i] == br.o && br.strock - 1 > 1)
				return (i);
		while (++q < pos_j + i)
			if (array[pos_i + i][q] == br.o && br.strock - 1 > 1)
				return (i);
		if (array[e][q] == br.o)
			return (i);
		i++;
	}
	return (i);
}

void	write_me(char **array, int *p, t_list br)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i][0])
	{
		j = -1;
		while (array[i][++j])
		{
			if (i > p[1] - 1 && i < p[1] + p[0]
				&& j > p[2] - 1 && j < p[2] + p[0])
				write(1, &br.x, 1);
			else
				write(1, &array[i][j], 1);
		}
		write(1, "\n", 1);
		free(array[i]);
	}
	free(array[i]);
	free(array);
}

void	raspred_f(char **array, t_list br, int i, int j)
{
	int	p[3];
	int	q;

	p[0] = 0;
	while (++i < br.strock)
	{
		j = -1;
		while (++j < br.strin)
		{
			q = riad_scuare(array, i, j, br);
			if (q > p[0])
			{
				p[0] = q;
				p[1] = i;
				p[2] = j;
			}
		}
	}
	write_me (array, p, br);
}
