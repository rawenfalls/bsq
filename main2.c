#include "ft_list.h"

void	prometh(char	**array, t_list br)
{
	int	i;

	i = -1;
	if (br.error)
	{
		write(2, "map error\n", 10);
		while (array[++i])
		{
			free(array[i]);
		}
		free(array[i]);
		free(array);
	}
	else
		raspred_f (array, br, -1, 0);
}

int	check_fd(int i, char **b)
{
	int	fd;

	fd = open(b[i], O_RDONLY);
	close(fd);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	return (fd);
}
