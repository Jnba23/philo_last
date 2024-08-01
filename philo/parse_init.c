/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:37:04 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 09:42:23 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	init_data(t_data *data, int ac, char **av)
{
	data->meals_num = -1;
	data->iter = true;
	data->phils_num = ft_atoi(av[1]);
	if (ft_atoi(av[1]) == 0)
		return (2);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (2);
		data->meals_num = ft_atoi(av[5]);
	}
	data->start_time = get_current_time();
	if (pthread_mutex_init(&data->mut_last_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mut_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mut_meals_eaten, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mut_iter, NULL) != 0)
		return (1);
	return (malloc_arrs(data));
}

int	malloc_arrs(t_data *data)
{
	int	i;

	i = -1;
	data->phils_arr = malloc(sizeof(t_philo) * data->phils_num);
	if (!data->phils_arr)
		return (1);
	data->forks_arr = malloc(sizeof(pthread_mutex_t) * data->phils_num);
	if (!data->phils_arr)
		return (1);
	return (0);
}

void	init_philos(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->phils_num)
	{
		data->phils_arr[i].philo_id = i + 1;
		data->phils_arr[i].last_meal = data->start_time;
		data->phils_arr[i].meals_eaten = 0;
		data->phils_arr[i].phil_state = STANDBY;
		data->phils_arr[i].l_fork = &data->forks_arr[i];
		data->phils_arr[i].r_fork = &data->forks_arr[(i + 1) % data->phils_num];
		data->phils_arr[i].data = data;
		i++;
	}
}
