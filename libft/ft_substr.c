/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-mah <mben-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:34:44 by mouad             #+#    #+#             */
/*   Updated: 2024/11/08 11:36:35 by mben-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*allocated;
	size_t	s_len;

	if (!s)
		return (NULL);
	allocated = malloc(len + 1);
	if (!allocated)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	while (i < len)
	{
		allocated[i] = s[start + i];
		i++;
	}
	allocated[i] = '\0';
	return (allocated);
}
