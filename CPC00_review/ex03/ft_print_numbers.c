/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaguchishohei <yamaguchishohei@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:19:53 by shyamagu          #+#    #+#             */
/*   Updated: 2021/08/08 08:42:18 by yamaguchish      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	moji;

	moji = '0';
	while (moji <= '9')
	{
		write(1, &moji, 1);
		moji++ ;
	}
	return ;
}
