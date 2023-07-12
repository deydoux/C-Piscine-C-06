/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:35:01 by deydoux           #+#    #+#             */
/*   Updated: 2023/07/12 11:38:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_tab(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
		ft_swap(&tab[i++], &tab[j--]);
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

	ft_rev_tab(argv, argc);
	i = 0;
	while (i < argc - 1)
	{
		ft_putstr(argv[i++]);
		ft_putstr("\n");
	}
}
