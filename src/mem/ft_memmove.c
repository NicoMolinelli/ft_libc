/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:08:55 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:08:56 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			*(char *)(dst + len - 1) = *(char *)(src + len - 1);
			len--;
		}
	}
	return (dst);
}
