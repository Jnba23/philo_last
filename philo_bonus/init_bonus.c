/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 05:12:22 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 11:02:58 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_data *data, int ac, char **av)
{
	u_int64_t	time;

	time = get_current_time();
	data->meals_num = -1;
	data->phils_num = ft_atoi(av[1]);
	if (data->phils_num == 0)
		return (1);
	data->tt_die = (u_int64_t)ft_atoi(av[2]);
	data->tt_eat = (u_int64_t)ft_atoi(av[3]);
	data->tt_sleep = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (1);
		data->meals_num = ft_atoi(av[5]);
	}
	data->start_time = time;
	create_semaphores(data);
	init_philos(data);
	return (0);
}

void	init_philos(t_data *data)
{
	int		i;

	data->philos = malloc(sizeof(t_philo) * data->phils_num);
	if (!data->philos)
		exit (1);
	i = -1;
	while (++i < data->phils_num)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].data = data;
		data->philos[i].meals_eaten = 0;
	}
}
