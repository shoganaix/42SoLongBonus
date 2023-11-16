/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:37:03 by msoriano          #+#    #+#             */
/*   Updated: 2023/10/04 16:35:28 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_formatcheck(char c, va_list args, int *result)
{
	if (c == 'c')
		ft_putcharacter_length((char)va_arg(args, int), result);
	else if (c == 's')
		ft_string(va_arg(args, char *), result);
	else if (c == 'p')
		ft_pointer(va_arg(args, size_t), result);
	else if (c == 'd' || c == 'i')
		ft_decimal(va_arg(args, int), 1, result);
	else if (c == 'u')
		ft_unsignedint(va_arg(args, unsigned int), result);
	else if (c == 'x')
		ft_hexadecimal(va_arg(args, unsigned int), 'x', result);
	else if (c == 'X')
		ft_hexadecimal(va_arg(args, unsigned int), 'X', result);
	else if (c == '%')
		ft_putcharacter_length('%', result);
}

int	ft_printf(char const *format, ...)
{
	int		result;
	va_list	args;

	va_start(args, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			ft_formatcheck(*format, args, &result);
		}
		else
			result = result + write(1, format, 1);
	format ++;
	}
	va_end(args);
	return (result);
}
