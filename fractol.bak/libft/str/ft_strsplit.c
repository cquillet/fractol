/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:25:01 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:35:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_words(char const *s, char c, size_t *start)
{
	size_t	nb_words;
	size_t	i;

	if (s == NULL)
		return (0);
	nb_words = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	*start = i;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		nb_words++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	nb_words;
	size_t	len_word;
	size_t	i;

	nb_words = get_nb_words(s, c, &i);
	if (!(split = (char **)malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	split[nb_words] = 0;
	if (nb_words == 0)
		return (split);
	nb_words = 0;
	while (s[i])
	{
		len_word = 0;
		while (s[i + len_word] && s[i + len_word] != c)
			len_word++;
		split[nb_words] = ft_strsub(s, i, len_word);
		nb_words++;
		i += len_word;
		while (s[i] && s[i] == c)
			i++;
	}
	return (split);
}
