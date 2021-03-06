/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:11:54 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:13:04 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		swap_a(stack_a);
		ft_putendl_fd("sa", 1);
	}
	if (!check_sorted(stack_a))
	{
		reverse_rotate_a(stack_a);
		ft_putendl_fd("rra", 1);
	}
	if (!check_sorted(stack_a))
	{
		swap_a(stack_a);
		ft_putendl_fd("sa", 1);
	}
}

void	ra_or_rra(int index, int jndex, t_stack **stack_a)
{
	if (jndex > index)
	{
		rotate_a(stack_a);
		ft_putendl_fd("ra", 1);
	}
	else
	{
		reverse_rotate_a(stack_a);
		ft_putendl_fd("rra", 1);
	}
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		smallest;
	int		jndex;
	int		index;

	smallest = get_smallest_number(*stack_a);
	jndex = ft_lstsize(*stack_a) / 2;
	tmp = *stack_a;
	while (tmp->number != smallest)
	{
		index = get_index(*stack_a, smallest);
		ra_or_rra(index, jndex, stack_a);
		tmp = *stack_a;
	}
	if (check_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	sort_lessten(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_a) != 3 && !check_sorted(stack_a))
		push_smallest(stack_a, stack_b);
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) != 0)
	{
		push_a(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
	{
		swap_a(stack_a);
		ft_putendl_fd("sa", 1);
	}
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size <= 10)
		sort_lessten(stack_a, stack_b);
	else
		sort_moreten(stack_a, stack_b);
}
