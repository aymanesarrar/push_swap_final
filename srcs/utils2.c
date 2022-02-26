/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:13:18 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 18:25:23 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	get_index(t_stack *stack_a, int number)
{
	t_stack	*tmp;
	int		index;

	tmp = stack_a;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->number == number)
			break ;
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	get_smallest_number(t_stack *stack_a)
{
	int		smallest;
	t_stack	*tmp;

	if (!stack_a)
		return (0);
	tmp = stack_a;
	smallest = tmp->number;
	while (tmp != NULL)
	{
		if (tmp->number < smallest)
			smallest = tmp->number;
		tmp = tmp->next;
	}
	return (smallest);
}

int	check_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return (0);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	*copy_stack(t_stack **stack_a, int *stack_size)
{
	t_stack	*tmp;
	int		*stack;
	int		index;

	*stack_size = ft_lstsize(*stack_a);
	stack = (int *)malloc(*stack_size * sizeof(int));
	if (!stack)
		return (NULL);
	index = 0;
	tmp = *stack_a;
	while (index < *stack_size)
	{
		stack[index] = tmp->number;
		index++;
		tmp = tmp->next;
	}
	return (stack);
}

void	sort_moreten(t_stack **stack_a, t_stack **stack_b)
{
	int	*tab;

	tab = sort_array_parts(stack_a);
	move_to_b(stack_a, stack_b, tab);
	sort_lessten_two(stack_a, stack_b);
	push_everything_back(stack_a, stack_b);
	free(tab);
}
