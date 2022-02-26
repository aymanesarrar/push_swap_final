/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:19:03 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:07:22 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	get_largest(t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;

	max = (*stack_b)->number;
	tmp = *stack_b;
	while (tmp != NULL)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

void	push_everything_back(t_stack **stack_a, t_stack **stack_b)
{	
	if (*stack_b)
	{
		if (check_sorted(stack_a))
		{
			while (*stack_b)
			{
				if (ft_lstsize(*stack_b) == 1)
				{
					push_a(stack_a, stack_b);
					ft_putendl_fd("pa", 1);
					break ;
				}
				push_largest_to_a(stack_a, stack_b);
			}
		}
	}
}

void	rb_or_rrb(int index, int jndex, t_stack **stack_b)
{
	if (jndex > index)
	{
		rotate_b(stack_b);
		ft_putendl_fd("rb", 1);
	}
	else
	{
		reverse_rotate_b(stack_b);
		ft_putendl_fd("rrb", 1);
	}
}

void	push_largest_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		largest;
	int		jndex;
	int		index;

	largest = get_largest(stack_b);
	jndex = ft_lstsize(*stack_b) / 2;
	tmp = *stack_b;
	while (tmp->number != largest)
	{
		index = get_index(*stack_b, largest);
		rb_or_rrb(index, jndex, stack_b);
		tmp = *stack_b;
	}
	if (tmp->number == largest)
	{
		push_a(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void	sort_stack(int *tab, int size)
{
	int	tmp;
	int	index;
	int	jndex;

	index = 0;
	while (index < size)
	{
		jndex = index + 1;
		while (jndex < size)
		{
			if (tab[jndex] < tab[index])
			{
				tmp = tab[jndex];
				tab[jndex] = tab[index];
				tab[index] = tmp;
			}
			jndex++;
		}
		index++;
	}
}
