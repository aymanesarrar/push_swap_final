/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:48:52 by aysarrar          #+#    #+#             */
/*   Updated: 2022/02/25 23:17:27 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;

	if (ac > 1)
	{
		numbers = get_numbers(av);
		push_elements(&stack_a, numbers);
		stack_b = NULL;
		if (check_sort(&stack_a))
		{
			free_2d(numbers);
			free_stack(&stack_a);
			return (0);
		}
		sort(&stack_a, &stack_b);
		free_2d(numbers);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
