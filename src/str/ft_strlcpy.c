/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:39 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:39 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
