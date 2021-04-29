#include "libft/libft.h"

int		check_dup(int *nbs, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i <= size)
	{
		tmp = nbs[i];
		j = 0;
		while (nbs[++j])
		{
			if (tmp == nbs[j] && i != j)
				return (0);
		}
	}
	return (1);
}

int		check_digit(char **nbs)
{
	int i;

	i = 0;
	while (nbs[++i])
	{
		if (!ft_isstingdigit(nbs[i]))
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int *nbs;
	int i;

	if (argc < 2)
		return (0);
	nbs = (int*)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argv[++i])
		nbs[i - 1] = ft_atoi(argv[i]);
	if (!check_digit(argv) || !check_dup(nbs, argc))
		printf("KO\n");
	else
		printf("OK\n");
	free(nbs);
	return (0);
}
