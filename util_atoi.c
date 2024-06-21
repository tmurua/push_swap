/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:27 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/21 01:57:25 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free allocated memory for stack_a, ac and av, and raise an error. */
static void	free_error_exit(t_node *stack_a, int ac, char **av)
{
	free_all(stack_a, ac, av);
	write(2, "Error\n", 6);
	exit(1);
}

/* Convert a string 's' to an integer with error handling.
1. Handle leading whitespace
2. Check for invalid input (empty string, invalid chars, or invalid sign)
3. Handle '+' or '-' sign
4. Convert numeric characters to an integer
5. Check for integer overflow or underflow */
int	custom_atoi(const char *s, t_node *stack_a, int ac, char **av)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (!s[i] || ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1])))
		free_error_exit(stack_a, ac, av);
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	number = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			free_error_exit(stack_a, ac, av);
		else
			number = number * 10 + (s[i] - '0');
		i++;
	}
	if ((sign * number < INT_MIN) || (sign * number > INT_MAX))
		free_error_exit(stack_a, ac, av);
	return (sign * number);
}
