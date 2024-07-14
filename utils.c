/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:45:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 19:08:14 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	meal_num_opt(t_data *data)
{
	bool opt;

	opt = false;
	if (data->meals_num > 0)
		opt = true;
	return (opt);
}

u_int64_t get_current_time()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(u_int64_t tt_sleep)
{
	u_int64_t	start;

	start = get_current_time();
	while (get_current_time() - start < tt_sleep)
		usleep(50);
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

void	free_ressources(t_data *data)
{
	int	i;

	i = 0;
	(void)data;
	while (i < data->phils_num)
	{
		pthread_mutex_destroy(&data->forks_arr[i++]);
		pthread_mutex_destroy(&data->phils_arr[i].mut_meals_eaten);
		pthread_mutex_destroy(&data->phils_arr[i].mut_phil_state);
		pthread_mutex_destroy(&data->phils_arr[i++].mut_last_meal);
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->mut_iter);
	free(data->phils_arr);
	free(data->forks_arr);
	free(data);
}
