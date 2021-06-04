/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:54:43 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/01 21:32:19 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	size_t				i;
	unsigned long long	num;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= 48)
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	if (num > 9223372036854775807 && (sign == 1))
		return (-1);
	else if (num > 9223372036854775807 && (sign == -1))
		return (1);
	return ((int)num * sign);
}
