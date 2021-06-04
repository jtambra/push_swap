/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:53:40 by jtambra           #+#    #+#             */
/*   Updated: 2021/06/03 21:23:13 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	str_is_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	args_are_digits(char **args)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		if (!str_is_digit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	find_duplicates(char **args)
{
	int	i;
	int	arr;

	i = 1;
	while (args[i])
	{
		arr = 1;
		while (args[arr])
		{
			if (arr != i)
			{
				if (!ft_strcmp(args[i], args[arr]))
					return (1);
			}
			arr++;
		}
		i++;
	}
	return (0);
}

int	fill_stack_a(char **args, t_list **stack_a)
{
	int		i;
	t_data	*data;	
	t_list	*tmp;

	i = 1;
	while (args[i])
	{
		data = (t_data *)ft_calloc(1, sizeof(t_data));
		if (!data)
		{
			ft_lstclear(stack_a, NULL);
			printf("Error\nStack should contain only int data-type values");
			return (-1);
		}
		data->value = ft_atoi(args[i]);
		tmp = ft_lstnew(data);
		if (!tmp)
		{
			free(data);
			ft_lstclear(stack_a, NULL);
			printf("Error\nStack should contain only int data-type values");
			return (-1);
		}
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	return (0);
}

void	ft_print_data(t_data *data)
{
	printf("data: ");
	printf("value - %d | order - %d | flag - %d\n", data->value, data->order, data->flag);
}

t_data	*data_copy(void *data)
{
	t_data *copy;

	copy = (t_data *)ft_calloc(1, sizeof(t_data));
	copy->value = (((t_data *)data)->value);
	return (copy);
}

void	free_data(void *data)
{
	if ((t_data *)data)
		free((t_data *)data);
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////ВОТ ЗДЕСЬ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

	// t_list	*copy;
	// t_list	*sorted;

	// ft_bzero(&sorted, sizeof(t_list));
	// copy = ft_lstmap(stack_a, (void *(*)(void *))data_copy, (void (*)(void *))free_data);
	// if (!copy)
	// {
	// 	free(&stack_a);
	// 	printf("Error\nCopy of stack A is not created\n");
	// 	exit(1);
	// }

void	lst_set_order(t_list *stack_a)
{
	t_list	*tmp = stack_a;
	t_list	*maximum;
	int		order = ft_lstsize(stack_a);
	int64_t	max = INT64_MIN;
	int64_t	last_max = INT64_MAX;
	
	while (order)
	{
		if ((((t_data *)stack_a->content)->value > max) &&
			(((t_data *)stack_a->content)->value < last_max))
		{
			max = ((t_data *)stack_a->content)->value;
			maximum = stack_a;
		}
		stack_a = stack_a->next;
		if (!stack_a)
		{
			((t_data *)(maximum->content))->order = order;
			--order;
			stack_a = tmp;
			last_max = max;
			max = INT64_MIN;
		}
	}
	while (tmp)
	{
		printf("stack_a: %d order: %d\n", ((t_data *)tmp->content)->value,
			((t_data *)tmp->content)->order);
		tmp = tmp->next;
	}
}

void	put_args_to_stack(char **args, t_stacks *stacks)
{
	if (fill_stack_a(args, &(stacks->stack_a)))
	{
		printf("Error\nStack should contain only int data-type values");
		exit(1);
	}
	lst_set_order(stacks->stack_a);
    ft_bzero(&stacks->stack_b, sizeof(t_list));
}

int	args_are_sorted(char **args)
{
	int	i;

	i = 1;
	while (args[i] && args[i + 1])
	{
		if ((ft_atoi(args[i])) < (ft_atoi(args[i + 1])))
			i++;
		else
			return (0);
	}
	return (1);
}

void	push_swap(char **args)
{
	t_stacks	stacks;

	if (!args_are_digits(args))
	{
		printf("Error\nStack should consist only digits\n");
		exit(1);
	}
	if (find_duplicates(args))
	{
		printf("Error\nDigits should not be duplicate\n");
		exit(1);
	}
	if (args_are_sorted(args))
	{
		printf("Digits are sorted\n");
		exit(0);
	}
	ft_bzero(&stacks, sizeof(t_stacks));
	put_args_to_stack(args, &stacks);
	printf("before: %d\n",((t_data *)stacks.stack_a->content)->value);
	//lst_sort(stacks.stack_a, stacks.stack_b, stacks.operations);
	printf("after all a: %d\n",((t_data *)stacks.stack_a->content)->value);
//	printf("after all b: %d\n",((t_data *)stacks.stack_b->content)->value);
	printf("DONE\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("No arguments\n");
		exit(1);
	}
	else
		push_swap(argv);

	return (0);
}

