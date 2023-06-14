/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 23:42:05 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/26 00:00:05 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/**
 * @brief Prints a string
 *
 * @param str String to print
 * @return int Number of characters printed
 */
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (write(1, str, i));
}

/**
 * @brief Prints a character
 *
 * @param c Character to print
 * @return int Number of characters printed
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * @brief Prints a number
 *
 * @param num Number to print
 * @return int Number of characters printed
 */
int	ft_putnum(int num)
{
	int	cnt;

	cnt = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		cnt += ft_putchar('-');
		num = -num;
	}
	return (cnt + ft_base_itoa(num, "0123456789", 10));
}

/**
 * @brief Prints an unsigned number
 *
 * @param num Number to print
 * @return int Number of characters printed
 */
int	ft_putunum(unsigned int num)
{
	return (ft_base_itoa(num, "0123456789", 10));
}

/**
 * @brief Prints a hexadecimal number
 *
 * @param num Number to print
 * @param x 'X' for uppercase, 'x' for lowercase
 * @return int Number of characters printed
 */
int	ft_puthex(unsigned int num, char x)
{
	if (x == 'X')
		return (ft_base_itoa(num, "0123456789ABCDEF", 16));
	else
		return (ft_base_itoa(num, "0123456789abcdef", 16));
}
