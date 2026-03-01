/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:33:01 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/23 23:18:48 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abss(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i <= size / 2)
	{
		temp = str[i];
		str[i] = str[size - i];
		str[size - i] = temp;
		i++;
	}
	return (str);
}

static int	count_size(int n)
{
	int	count;

	if (n == -2147483648)
		return (11);
	count = 1;
	if (n < 0)
	{
		count++;
		n = abss(n);
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	add_digits(char *nbr, int n)
{
	int	i;
	int	r;
	int	nb;

	i = 0;
	if (n == -2147483648)
	{
		nb = -214748364;
		nbr[i++] = '8';
		nb = abss(nb);
	}
	else
		nb = abss(n);
	while (nb)
	{
		r = nb % 10;
		nbr[i++] = 48 + r;
		nb = nb / 10;
	}
	if (i == 0)
		nbr[i++] = '0';
	if (n < 0)
		nbr[i++] = '-';
	nbr[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		size;
	char	*nbr;

	size = count_size(n);
	nbr = malloc(sizeof(char) * size + 1);
	if (!nbr)
		return (0);
	add_digits(nbr, n);
	return (ft_strrev(nbr));
}
