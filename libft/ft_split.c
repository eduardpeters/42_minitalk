/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:04:50 by epeters-          #+#    #+#             */
/*   Updated: 2022/11/27 17:48:11 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			return (len);
		len++;
		s++;
	}
	return (len);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s && *s == c)
				s++;
		}
		else
		{
			if (*(s + 1) == 0)
				count++;
			s++;
		}
	}
	return (count);
}

static char	**ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_wordsplit(char **tab, size_t count, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		tab[i] = (char *)(malloc(sizeof(**tab) * (len + 1)));
		if (!tab[i])
			return (ft_free_split(tab));
		ft_strlcpy(tab[i], s, len + 1);
		s += len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	tab = (char **)(malloc(sizeof(*tab) * (count + 1)));
	if (!tab)
		return (NULL);
	return (ft_wordsplit(tab, count, s, c));
}
