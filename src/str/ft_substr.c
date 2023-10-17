/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:10:00 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:10:00 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	actual_length;
	char	*substr;

	actual_length = 0;
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (s[actual_length + start] && actual_length < len)
		actual_length++;
	substr = malloc(sizeof(char) * (actual_length + 1));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, actual_length + 1);
	return (substr);
}
