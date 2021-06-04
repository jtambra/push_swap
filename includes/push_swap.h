/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:00:29 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/03 21:22:53 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define INT64_MAX 9223372036854775807
# define INT64_MIN -9223372036854775807


typedef struct	s_stacks
{
	char	**operations;
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stacks;

typedef struct	s_data
{
	int	value;
	int	order;
	int	flag;
}				t_data;

void	swap(t_list *stack, char ***operations, char *name_stack);
void	push(t_list **from, t_list **to, char ***operations, char *name_stack);
void	rotate(t_list **stack, char ***operations, char *name_stack);
void	reverse_rotate(t_list **stack, char ***operations, char *name_stack);
void	lst_sort(t_list *stack_a, t_list *stack_b, char **operations);

#endif
