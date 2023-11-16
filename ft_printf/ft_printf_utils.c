/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:26:36 by msoriano          #+#    #+#             */
/*   Updated: 2023/10/04 16:35:31 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal(int nb, int fd, int *length)
{
	unsigned int	n;
	char			digit;

	if (nb < 0)
	{
		write(fd, "-", 1);
		(*length)++;
		n = (unsigned int)(nb * -1);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_decimal(n / 10, fd, length);
	digit = (char)(n % 10 + '0');
	write(fd, &digit, 1);
	(*length)++;
}

void	ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		write(1, &args[i], 1);
		(*length)++;
		i++;
	}
}

void	ft_unsignedint(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsignedint(u / 10, length);
	write(1, &(char){(u % 10) + '0'}, 1);
	(*length)++;
}

void	ft_pointer(size_t pointer, int *length)
{
	char	string[17];
	int		i;
	char	*base_character;

	i = 0;
	base_character = "0123456789abcdef";
	write(1, "0x", 2);
	(*length) += 2;
	if (pointer == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i > 0)
	{
		i --;
		ft_putcharacter_length(string[i], length);
	}
}

void	ft_hexadecimal(unsigned int x, char c, int *length)
{
	char	string[25];
	char	*base_character;
	int		i;

	i = 0;
	if (c == 'X')
	base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	if (x == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	while (i > 0)
	{
		i --;
		ft_putcharacter_length(string[i], length);
	}
}
