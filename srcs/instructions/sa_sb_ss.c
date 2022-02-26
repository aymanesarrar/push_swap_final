/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:14:25 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:06:39 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*tmp;
	int		tmp_number;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	tmp_number = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = tmp_number;
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*tmp;
	int		tmp_number;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	tmp_number = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = tmp_number;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
