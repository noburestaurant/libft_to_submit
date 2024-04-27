/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:15:44 by hnakayam          #+#    #+#             */
/*   Updated: 2024/04/27 20:16:51 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rest_of_atoi(int sign, unsigned long ans)
{
	if (ans > LONG_MAX && sign == 1)
		return ((int)LONG_MAX);
	if (ans - 1 > LONG_MAX && sign == -1 && ans != 0)
		return ((int)LONG_MIN);
	if (ans == 2147483648 && sign == -1)
		return (-2147483648);
	return ((int)ans * sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	ans;

	i = 0;
	ans = 0;
	sign = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (ans > ans * 10 + str[i] - '0')
			return (0);
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (rest_of_atoi(ans, sign));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*num_str = " \t\v\n\f\r+2147483647";
// 	printf("%d\n", ft_atoi(num_str));
// 	printf("%d\n", atoi(num_str));
// 	return (0);
// }
