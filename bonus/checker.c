/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:32:03 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:26:17 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_valid_instruction(char *str)
{
	if (check_space(str))
		return (0);
	if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

static void	apply_instructions(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_b(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rotate_ab(stack_a, stack_b);
}

static int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(1);
	while (str)
	{
		if (check_valid_instruction(str))
		{
			ft_putendl_fd("Error", 1);
			return (0);
		}
		else
			apply_instructions(str, stack_a, stack_b);
		str = get_next_line(1);
	}
	if (check_sorted(stack_a) && !*stack_b)
	{
		ft_putendl_fd("OK", 1);
		return (1);
	}
	else
		ft_putendl_fd("KO", 1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;

	if (ac > 1)
	{
		numbers = get_numbers(av);
		push_elements(&stack_a, numbers);
		stack_b = NULL;
		if (checker(&stack_a, &stack_b) == 1)
		{
			free_2d(numbers);
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (0);
		}
		else
		{
			free_2d(numbers);
			free_stack(&stack_a);
			return (1);
		}
	}
	return (0);
}
