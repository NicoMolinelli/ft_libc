/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:57 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:57 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;

	while (ft_strchr(set, (int) *s1))
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, (int) s1[len - 1]) && len)
		len--;
	return (ft_substr(s1, 0, len));
}
