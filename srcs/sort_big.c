/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:27:05 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:20:15 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	*sort_array_parts(t_stack **stack_a)
{
	int	stack_size;
	int	*table;
	int	index;
	int	*arr;

	table = copy_stack(stack_a, &stack_size);
	sort_stack(table, stack_size);
	arr = malloc(PARTS * sizeof(int));
	index = 0;
	while (index < PARTS)
	{
		arr[index] = table[stack_size / PARTS * index];
		index++;
	}
	free(table);
	return (arr);
}

void	move_number_to_b(t_stack **stack_a, t_stack **stack_b, int nb)
{
	int		stack_size;
	int		index;
	t_stack	*stack_tmp;

	stack_tmp = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	index = 0;
	while (index < stack_size)
	{
		if (stack_tmp->number <= nb)
		{
			push_b(stack_a, stack_b);
			ft_putendl_fd("pb", 1);
		}
		else
		{
			rotate_a(stack_a);
			ft_putendl_fd("ra", 1);
		}
		index++;
		stack_tmp = *stack_a;
	}
}

void	sort_lessten_two(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = 0;
	while (ft_lstsize(*stack_a) != 3 && !check_sorted(stack_a))
	{
		push_smallest(stack_a, stack_b);
		index++;
	}
	sort_three(stack_a);
}

int	there_is_smaller_in_stack(t_stack **stack_a, int biggest)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->number < biggest)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	index;

	index = 0;
	while (index < PARTS)
	{
		if (there_is_smaller_in_stack(stack_a, tab[index]))
			move_number_to_b(stack_a, stack_b, tab[index]);
		index++;
	}
}
