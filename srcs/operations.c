/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:39 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/03 22:20:09 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_new_arr(char **dst, char **src, const char *add)
{
	size_t i;

	i = 0;
	while(src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = ft_strdup(add);
	dst[i + 1] = NULL;
}

void	ft_arrjoin(char **arr, const char *add)
{
	char	*tmp;
	char	**tmp_arr;

	if (!add)
		return ;
	if (!arr)
	{
		printf("%s\n", "yes"); 
		*arr = ft_calloc(1, sizeof(1));
		printf("%s\n", *arr);
		tmp = *arr;
		*arr = ft_strjoin(*arr, add);
		free(&tmp);
		if (!(*arr))
			return ;
	}
	else
	{
		tmp_arr = arr;
		arr = (char **)malloc(sizeof(char *) * (ft_arrlen(arr) + 2));
		if (!arr)
		{
			ft_free_strs(tmp_arr);
			return ;
		}
		else
			fill_new_arr(arr, tmp_arr, add);
		ft_free_strs(tmp_arr);
	}
}

void	swap(t_list *stack, char ***operations, char *name_stack)
{
	t_data *tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_arrjoin(*operations, name_stack);
}

void	push(t_list **from, t_list **to, char ***operations, char *name_stack)
{
	t_list	*tmp;

	if (!from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, tmp);
	ft_arrjoin(*operations, name_stack);
}

void	rotate(t_list **stack, char ***operations, char *name_stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);	
	ft_arrjoin(*operations, name_stack);
}

void	reverse_rotate(t_list **stack, char ***operations, char *name_stack)
{
	t_list	*iter;
	t_list	*tmp;

	iter = *stack;
	if (!iter)
		return ;
	while (iter->next && iter->next->next)
		iter = iter->next;
	tmp = iter->next;
	iter->next = NULL;
	ft_lstadd_front(stack, tmp);
	ft_arrjoin(*operations, name_stack);
}
