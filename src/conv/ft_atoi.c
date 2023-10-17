/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:07:12 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:07:14 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) || ft_isspace(*str))
	{
		if (ft_isspace(*str))
			str++;
		else
		{
			n = n * 10 + (*str - '0');
			str++;
		}
	}
	return (n * sign);
}
