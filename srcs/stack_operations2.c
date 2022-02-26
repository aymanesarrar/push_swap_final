/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:16:33 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:18:05 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	pop(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (1);
}

void	push_elements(t_stack **stack, char **av)
{
	long	number;
	int		index;

	index = numbers_len(av) - 1;
	if (check_numbers(av))
	{
		while (index >= 0)
		{
			number = ft_atoi(av[index]);
			if (number < -2147483648 || number > 2147483647)
				handle_errors();
			if (!check_number(stack, number))
				free_and_exit(stack);
			if (!insert_first(stack, ft_atoi(av[index])))
				free_and_exit(stack);
			index--;
		}
	}
	else
		handle_errors();
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->number, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	remove_last(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

int	numbers_len(char **numbers)
{
	int		i;

	i = 0;
	while (numbers[i])
		i++;
	return (i);
}
