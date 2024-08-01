/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:45:27 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 09:43:33 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	meal_num_opt(t_data *data)
{
	bool	opt;

	opt = false;
	if (data->meals_num > 0)
		opt = true;
	return (opt);
}

long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long tt_sleep)
{
	long long	start;

	start = get_current_time();
	while (get_current_time() - start < tt_sleep)
		usleep(500);
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

void	free_ressources(t_data *data, int i)
{
	int	j;

	j = 0;
	pthread_mutex_destroy(&data->mut_last_meal);
	pthread_mutex_destroy(&data->mut_meals_eaten);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_iter);
	if (i == 2)
	{
		while (j < data->phils_num)
			pthread_mutex_destroy(&data->forks_arr[j++]);
	}
	if (i == 1)
	{
		while (j < data->phils_num)
		{
			pthread_mutex_destroy(&data->forks_arr[j]);
			if (data->phils_num != 1)
				pthread_mutex_destroy(&data->phils_arr[j].mut_phil_state);
			j++;
		}
	}
	free(data->forks_arr);
}
