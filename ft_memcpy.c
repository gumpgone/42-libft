/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:38:56 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/03 11:11:40 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dest2;
	const char		*src2;
	unsigned long	i;

	if (!(dest || src))
		return (0);
	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	while (i < n && (src2[i] || dest2[i]))
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
