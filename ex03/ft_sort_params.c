/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:33:07 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/12 19:04:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_tab(char **tab, int size)
{
	int	index;
	int	before;

	index = 1;
	while (index < size)
	{
		before = index - 1;
		while (before >= 0 && ft_strcmp(tab[before], tab[before + 1]) > 0)
		{
			ft_swap(&tab[before], &tab[before + 1]);
			before--;
		}
		index++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort_tab(++argv, --argc);
	i = 0;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putstr("\n");
	}
}
