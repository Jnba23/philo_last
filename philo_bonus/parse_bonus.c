/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:51:29 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 17:14:50 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (digits_only(av[i]) == 1 || ft_atoi(av[i]) > INT_MAX
			|| ft_atoi(av[i]) < 0 || ft_strlen(av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	digits_only(char *s)
{
	int	i;
	int	sign_count;

	sign_count = 0;
	i = 0;
	if (s[i] == '+' && ft_strlen(s) == 1)
		return (1);
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (s[i] == '+' && i == 0)
				sign_count++;
			else
				return (1);
		}
		i++;
	}
	if (sign_count > 1)
		return (1);
	return (0);
}

long long	ft_atoi(char *str)
{
	int					sign;
	long long			num;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num * sign);
}
