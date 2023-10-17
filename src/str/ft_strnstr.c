/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:50 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:51 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] && i < len)
	{
		if (i + ft_strlen(needle) > len)
			return (0);
		else if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle))))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
