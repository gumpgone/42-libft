/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:44:03 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/24 17:53:22 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{	
	unsigned int	i;
	unsigned int	j;
	unsigned int	save;

	j = ft_strlen(dest);
	i = 0;
	while (src[i] && (j + i + 1) < size)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (!src[i])
		dest[i + j] = 0;
	save = i;
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	if (j < size)
	{
		dest[save + j] = 0;
		return (i + j);
	}
	return (size + i);
}
