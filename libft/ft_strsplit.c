/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:53 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:53 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	wrd = ft_count_words(str, c);
	if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 1))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < wrd && str[i])
	{
		s[j] = ft_word(str, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
