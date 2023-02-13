/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:58:42 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/08 13:57:52 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Librairies
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// ft_print
// ft_printf.c
int				ft_printf(const char *format, ...);

// ft_check_args.c
void			ft_check_args(char format, va_list args, int *count);

// ft_print_nbr.c
void			ft_putnbr(int n, int *count);
void			ft_putnbr_base(long long int nbr, long long int size, \
char *base, int *count);		

// ft_print_char.c
void			ft_putchar(int c, int *count);
void			ft_putstr(char *s, int *count);

// get_next_line
// get_next_line.c
char			*get_next_line(int fd);
char			*read_the_line(char *buffer, int *end_file, int fd);
char			*next_line(char *buffer, int *end_file, int *i, int fd);
void			clean_buf(char *buffer, int *end_file);
char			*first_read(char *buffer, int *i);

// get_next_line_utils.c
unsigned int	next_line_len(char *buffer);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup(char *buffer);

//libft
// ft_itoa.c
char			*ft_itoa(int n);

#endif