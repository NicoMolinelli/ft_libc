/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:07:21 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:07:22 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char **buff, int fd, char *str)
{
	if (buff && buff[fd])
	{
		free(buff[fd]);
		buff[fd] = 0;
	}
	if (str)
		free(str);
	return (0);
}
