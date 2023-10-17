/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:08:47 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:08:48 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	search;

	i = 0;
	str = (unsigned char *)s;
	search = (unsigned char)c;
	while (i < n)
	{
		if (*(str + i) == search)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
