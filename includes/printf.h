/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 14:01:51 by mdekker       #+#    #+#                 */
/*   Updated: 2023/05/26 00:04:19 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_pseudoswitch(char *str, int i, va_list args);
int	ft_putpercent(void);
int	ft_putptr(unsigned long num);
int	ft_puthex(unsigned int num, char x);
int	ft_putnum(int num);
int	ft_putunum(unsigned int num);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_base_itoa(unsigned long num, const char *base_str, int base);
int	ft_counter(unsigned long num, int base);

#endif
