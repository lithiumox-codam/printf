/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 15:45:31 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/26 00:02:43 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/**
 * @brief Counts the number of digits in a number
 *
 * @param num Number to count digits of
 * @param base Base to count digits in
 * @return int Number of digits
 */
int	ft_counter(unsigned long num, int base)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		return (++cnt);
	while (num != 0)
	{
		num = num / base;
		cnt++;
	}
	return (cnt);
}

/**
 * @brief Converts a number to a string in a given base and prints it
 *
 * @param num Number to convert
 * @param base_str String of characters to use as base
 * @param base Base to convert to
 * @return int Number of characters printed
 */
int	ft_base_itoa(unsigned long num, const char *base_str, int base)
{
	int		cnt;
	char	*str;

	cnt = ft_counter(num, base);
	str = malloc(sizeof(char) * (cnt + 1));
	if (str)
	{
		str[cnt] = '\0';
		while (cnt != 0)
		{
			str[--cnt] = base_str[num % base];
			num /= base;
		}
		cnt = ft_putstr(str);
	}
	else
		return (0);
	return (free(str), cnt);
}

/**
 * @brief Prints a pointer
 *
 * @param num Pointer to print
 * @return int Number of characters printed
 */
int	ft_putptr(unsigned long num)
{
	return (write(1, "0x", 2) + ft_base_itoa(num, "0123456789abcdef", 16));
}

/**
 * @brief Prints a percentage sign
 *
 * @return int Number of characters printed
 */
int	ft_putpercent(void)
{
	return (ft_putchar('%'));
}
