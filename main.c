#include "ft_list.h"

void	bsq(t_list br, int c, int i, int fd)
{
	char	**array;
	int		j;

	array = (char **)malloc(sizeof(char **) * (br.strock + 1));
	fd = open(br.fn, O_RDONLY);
	while ((read(fd, &c, 1)))
	{
		if ((((c >= ' ') && (c <= '~'))) && (i >= 0))
		{
			if (((c != br.full_stop) && (c != br.o)))
				br.error = 1;
			j++;
			array[i][j] = c;
		}
		if (c == '\n')
		{
			if (i >= 0)
				array[i][++j] = '\0';
			j = -1;
			array[++i] = (char *)malloc(sizeof(char) * (br.strin));
		}
	}
	close (fd);
	prometh(array, br);
}

void	prometh2(t_list br)
{
	if (br.error)
		write(2, "map error\n", 10);
	else
		bsq(br, 0, -1, 0);
}

void	len1(char *fn, int fd, int len, int c)
{
	t_list	br;

	br.error = 0;
	br.fn = fn;
	br.strock = 0;
	br.strin = 0;
	fd = open(fn, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			br.strock++;
		if ((c >= ' ') && (c <= '~') && (br.strock == 1))
			br.strin++;
		if ((c >= ' ') && (c <= '~') && (br.strock > 1))
			len++;
		if ((c == '\n') && (br.strock > 2))
			if (len != br.strin)
				br.error = 1;
		if (c == '\n')
			len = 0;
	}
	close (fd);
	br = check_first_string(br, 0, 0, 0);
	prometh2(br);
}

void	terminal(int c, int i, int num)
{
	int	fd;

	fd = open("buff\0", O_TRUNC | O_WRONLY);
	while (read(0, &c, 1) != 0)
	{
		if ((i == 0) && (c != '\n'))
		{
			if ((c >= '0') && (c <= '9'))
				num = num * 10 + c - 48;
		}
		if (c == '\n')
			i++;
		if (num + 1 == i && i > 0)
		{
			write(fd, &c, 1);
			break ;
		}
		write(fd, &c, 1);
	}
	close(fd);
}

int	main(int a, char **b)
{
	int	i;

	i = 0;
	if (a == 1)
	{
		terminal(0, 0, 0);
		len1("buff\0", 0, 0, 0);
	}
	else if (a >= 2)
	{
		while (b[++i])
		{
			if (check_fd(i, b) != -1)
				len1(b[i], 0, 0, 0);
			if (i + 1 != a)
				write(1, "\n", 1);
		}
	}
	else
		write(2, "map error\n", 10);
	return (0);
}
