/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:45:11 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/04 14:14:35 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	count;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	if (ft_strlen((char *)haystack) == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		count = 0;
		j = 0;
		while (j < ft_strlen((char *)needle) && i + j < len
			&& i + j < ft_strlen((char *)haystack))
		{
			if (haystack[i + j] == needle[j])
				count++;
			j++;
		}
		if (count == ft_strlen((char *)needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
