/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaguchishohei <yamaguchishohei@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:57:03 by shyamagu          #+#    #+#             */
/*   Updated: 2021/08/08 09:30:08 by yamaguchish      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAXLINE 10

void	ft_print_combn(int n);
void	ft_putzero(int nb, int order);
void	ft_putnbr(int nb);
int		check(int a, int n);
int		put(int flag, int flag_camma, int a, int n);

void	ft_print_combn(int n)
{
	int			a;
	int			cp_n;
	int			max_n;
	int			flag_camma;
	int			flag;

	a = 0;
	cp_n = n;
	max_n = 1;
	flag_camma = 0;
	while (cp_n != 0)
	{
		max_n *= 10;
		cp_n--;
	}
	while (a < max_n)
	{
		flag = check(a, n);
		if (flag == 0)
		{
			flag_camma = put(flag, flag_camma, a, n);
		}
		a++;
	}
	return ;
}

int	put(int flag, int flag_camma, int a, int n)
{
	if (flag == 0)
	{
		if (flag_camma == 1)
		{
			write(1, &", ", 2);
		}
		ft_putzero(a, n);
		ft_putnbr(a);
		flag_camma = 1;
	}
	return (flag_camma);
}

int	check(int a, int n)
{
	int			cp_a;
	int			pos;
	int			flag;
	int			i;
	static int	arr_num[MAXLINE];

	i = 0;
	flag = 0;
	cp_a = a;
	pos = n - 1;
	while (pos >= 0)
	{
		arr_num[pos] = cp_a % 10;
		cp_a /= 10;
		pos--;
	}
	while (i < n - 1)
	{
		if (arr_num[i] >= arr_num[i + 1])
		{
			flag = 1;
		}
		i++;
	}
	return (flag);
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
