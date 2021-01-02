/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:03:10 by tarcay            #+#    #+#             */
/*   Updated: 2021/01/02 14:28:39 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char				**ft_clear_splitted(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char		**init_elems(char const *str, char c)
{
	int		count;
	int		nb_elems;
	char	**elems_tab;

	count = 0;
	nb_elems = 0;
	while (str[count])
	{
		while (str[count] != c && str[count])
			count++;
		while (str[count] == c && str[count])
			count++;
		if (str[count] != c && str[count])
			nb_elems++;
	}
	if (!(elems_tab = malloc(sizeof(char *) * (nb_elems + 1))))
		return (ft_clear_splitted(elems_tab));
	return (elems_tab);
}

static char		**init_word(char const *str, char **elems_tab, char c)
{
	int	count;
	int	nb_chars;
	int	index;

	count = 0;
	index = 0;
	while (str[count])
	{
		nb_chars = 0;
		while (str[count] == c && str[count])
			count++;
		while (str[count] != c && str[count])
		{
			count++;
			nb_chars++;
		}
		if (str[count] == c || str[count] == 0)
		{
			if (!(elems_tab[index] = malloc(sizeof(char) * (nb_chars + 1))))
				return (ft_clear_splitted(elems_tab));
			elems_tab[index][nb_chars + 1] = '\0';
			index++;
		}
	}
	return (elems_tab);
}

static char		**create_tab(char const *str, char **tab, char c)
{
	int	count;
	int	nb_chars;
	int	index;

	count = 0;
	index = 0;
	while (str[count])
	{
		nb_chars = 0;
		while (str[count] == c && str[count])
			count++;
		while (str[count] != c && str[count])
		{
			tab[index][nb_chars] = str[count];
			count++;
			nb_chars++;
		}
		tab[index][nb_chars] = '\0';
		index++;
	}
	str[count - 1] == c ? tab[index - 1] = 0 : tab[index];
	str[count - 1] != c ? tab[index] = 0 : 0;
	return (tab);
}

char			**ft_split(char const *s, const char c)
{
	char	**tab;

	if (c == '\0' && s[0] == '\0')
	{
		if (!(tab = malloc(sizeof(char) * 1)))
			return (NULL);
		tab[0] = 0;
		return (tab);
	}
	tab = init_elems(s, c);
	tab = init_word(s, tab, c);
	tab = create_tab(s, tab, c);
	return (tab);
}
