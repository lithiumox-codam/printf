/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 16:34:56 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/25 23:57:57 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/**
 * @brief The printf function
 *
 * @param str String to print
 * @param ... Arguments to print
 * @return int Number of characters printed
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	if (write(1, str, 0) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_pseudoswitch((char *)str, i, args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

/**
 * @brief Switch function for the printf function
 *
 * @param str String to print
 * @param i Index of the string
 * @param args Arguments to print
 * @return int Number of characters printed
 */
int	ft_pseudoswitch(char *str, int i, va_list args)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[i] == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_putunum(va_arg(args, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_puthex(va_arg(args, unsigned int), str[i]));
	else if (str[i] == '%')
		if (str[i - 1] == '%')
			return (ft_putpercent());
	return (0);
}
