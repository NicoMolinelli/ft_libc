/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:09:54 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:09:54 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	char	*str;
	char	*last_chr;

	to_find = (char) c;
	str = (char *) s;
	last_chr = 0;
	while (*str)
	{
		if (*str == to_find)
			last_chr = str;
		str++;
	}
	if (*str == to_find)
		return (str);
	return (last_chr);
}
