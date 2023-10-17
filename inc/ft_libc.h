/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_libc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:10:13 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:10:14 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC_H
# define FT_LIBC_H

# include <unistd.h>

/*
* ASCII
*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);

/*
* CONVERSION 
*/
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
* FD UTILS 
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*
* MEMORY MANAGMENT 
*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char **buff, int fd, char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*
* STRING 
*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
* GET NEXT LINE
*/
char	*get_next_line(int fd);

#endif
