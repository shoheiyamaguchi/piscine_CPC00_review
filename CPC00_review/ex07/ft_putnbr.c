/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaguchishohei <yamaguchishohei@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:56:11 by shyamagu          #+#    #+#             */
/*   Updated: 2021/08/08 08:47:35 by yamaguchish      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putzeroorminus(int nb);

void	ft_putnbr(int nb)
{
	int		nb_cp;
	int		div_num;
	int		n;
	char	char_n;

	nb = ft_putzeroorminus(nb);
	div_num = 1;
	nb_cp = nb;
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

int	ft_putzeroorminus(int nb)
{
	if (0 > nb)
	{
		write(1, &"-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write(1, &"0", 1);
	}
	return (nb);
}
