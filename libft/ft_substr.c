/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:48:27 by epeters-          #+#    #+#             */
/*   Updated: 2022/06/19 20:07:02 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	substrlen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > (slen - start))
		substrlen = slen - start;
	else if (start > slen)
		substrlen = 0;
	else
		substrlen = len;
	str = (char *)(malloc(sizeof(*str) * (substrlen + 1)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, (substrlen + 1));
	return (str);
}
