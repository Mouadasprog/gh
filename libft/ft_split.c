/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:54:08 by mouad             #+#    #+#             */
/*   Updated: 2024/11/09 09:55:14 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*allocate_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		num_words;
	int		index;
	const char	*start;
	size_t	len;

	num_words = count_words(s, c);
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			start = s;
			len = 0;
			while (*s && *s != c)
			{
				s++;
				len++;
			}
			words[index] = allocate_word(start, len);
			if (!words[index])
			{
				while (index > 0)
				{
					free(words[--index]);
				}
				free(words);
				return (NULL);
			}
			index++;
		}
	}
	words[index] = NULL;
	return (words);
}
