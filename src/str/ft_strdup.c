/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:25 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:27 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
