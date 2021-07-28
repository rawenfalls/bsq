#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct s_list
{
	int		strock;
	int		strin;
	char	full_stop;
	char	o;
	char	x;
	int		error;
	char	*fn;	
}	t_list;

int		check_fl(t_list br);
t_list	check_first_string(t_list br, int c, int num, int j);
int		riad_scuare(char **array, int pos_i, int pos_j, t_list br);
void	write_me(char **array, int *p, t_list br);
void	raspred_f(char **array, t_list br, int i, int j);
void	prometh(char	**array, t_list br);
int		check_fd(int i, char **b);

#endif
