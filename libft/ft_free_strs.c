/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:08:59 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/03 20:09:03 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strs(char **strs)
{
	char	**tmp;

	if (!strs)
		return ;
	tmp = strs;
	while (*tmp != NULL)
	{
		if (*tmp)
			free(*tmp);
		tmp++;
	}
	free(strs);
}
