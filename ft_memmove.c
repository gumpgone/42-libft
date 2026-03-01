/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:40:10 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/03 13:13:57 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	unsigned int	i;

	if (!(dst || src))
		return (0);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < len)
	{	
		if (dst > src)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
		else
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
