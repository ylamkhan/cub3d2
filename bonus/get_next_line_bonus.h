/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:41:19 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:33:49 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int         ft_intsize(long nb);
int			ft_atoi(const char *str);
void		ft_putstr(char *s);
void        ft_putchar(char c);
int         ft_isdigit(int c);
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
void		*ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
void        *ft_memcpy(void *dst, void *src, size_t n);
void        ft_putnbr(long n);
int         ft_intsize(long nb);
size_t		ft_smallest(char *s, unsigned int start, size_t len);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
