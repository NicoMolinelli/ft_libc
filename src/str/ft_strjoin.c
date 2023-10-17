/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:32 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:33 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	n;

	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = malloc(sizeof(char) * n);
	if (!s)
		return (0);
	ft_strlcpy(s, s1, n);
	ft_strlcat(s, s2, n);
	return (s);
}
