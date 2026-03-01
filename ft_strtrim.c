/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhattab <wkhattab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:46:06 by wkhattab          #+#    #+#             */
/*   Updated: 2023/05/23 14:20:57 by wkhattab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_up(char *s1, unsigned int	*start, unsigned int	*end)
{	
	if (s1[0] == '\0')
	{
		*end = 0;
		*start = 1;
	}
	else if (*start == ft_strlen(s1))
	{
		*end = 0;
		*start = 1;
	}
	else if (*start == *end)
	{
		*end = 0;
		*start = 0;
	}
}

static int	s_set_in_s1(char *s1, char *set)
{
	int				i;
	int				j;
	unsigned int	count;

	if (!s1)
		return (1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		if (count == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	e_set_in_s1(char *s1, char *set)
{
	int				i;
	int				j;
	unsigned int	count;

	i = ft_strlen(s1) - 1;
	if (i == -1)
		i = 0;
	while (s1[i])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		if (count == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*str;

	if (!s1 || !set)
		return (0);
	if (s1[0] != '\0')
	{
		start = s_set_in_s1((char *)s1, (char *)set);
		end = e_set_in_s1((char *)s1, (char *)set);
	}
	set_up((char *)s1, &start, &end);
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	if (start == ft_strlen(s1) || s1[0] == '\0')
		str[0] = '\0';
	else if (start == end)
	{
		str[0] = s1[s_set_in_s1((char *)s1, (char *)set)];
		str[1] = '\0';
	}
	else
		ft_strlcpy(str, (char *)s1 + start, end - start + 2);
	return (str);
}
