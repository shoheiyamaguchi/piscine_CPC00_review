/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaguchishohei <yamaguchishohei@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:34:27 by shyamagu          #+#    #+#             */
/*   Updated: 2021/08/08 08:46:11 by yamaguchish      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putresult(int b, int c, int flag);
void	ft_putresult(int b, int c, int flag);
void	ft_putzero(int nb, int order);
void	ft_putnbr(int nb);

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	flag;

	flag = 0;
	a = 1;
	while (a < 10000)
	{
		b = a / 100;
		c = a % 100;
		if (b < c)
		{
			ft_putresult(b, c, flag);
			flag = 1;
		}
		a++;
	}
	return ;
}

void	ft_putresult(int b, int c, int flag)
{
	if (flag == 1)
	{
		write(1, &", ", 2);
	}
	ft_putzero(b, 2);
	ft_putnbr(b);
	write(1, &" ", 1);
	ft_putzero(c, 2);
	ft_putnbr(c);
}

void	ft_putzero(int nb, int order)
{
	int		nb_cp;

	nb_cp = nb;
	while (nb_cp != 0)
	{
		nb_cp = nb_cp / 10;
		order--;
	}
	while (order != 0)
	{
		write(1, &"0", 1);
		order--;
	}
	return ;
}

void	ft_putnbr(int nb)
{
	int		nb_cp;
	int		div_num;
	int		n;
	char	char_n;

	nb_cp = nb;
	div_num = 1;
	while (nb_cp != 0)
	{
		nb_cp = nb_cp / 10;
		div_num *= 10;
	}
	div_num /= 10;
	while (div_num != 0)
	{
		char_n = '0';
		n = nb / div_num;
		nb -= n * div_num;
		div_num /= 10;
		char_n += n;
		write(1, &char_n, 1);
	}
	return ;
}
