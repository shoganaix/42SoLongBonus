/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:00:24 by msoriano          #+#    #+#             */
/*   Updated: 2023/10/04 16:39:38 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void			ft_string(char *args, int *length);
void			ft_decimal(int nb, int fd, int *length);
void			ft_unsignedint(unsigned int u, int *length);
int				ft_printf(const char *format, ...);
void			ft_formatcheck(char c, va_list args, int *result);
void			ft_pointer(size_t pointer, int *length);
void			ft_hexadecimal(unsigned int x, char c, int *length);
void			ft_putcharacter_length(char c, int *length);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strrchr(const char *s, int c);

#endif
