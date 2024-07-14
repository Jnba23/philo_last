/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:07:48 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 19:08:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_threads(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->phils_num)
	{
		pthread_create(&data->phils_arr[i].philo, NULL, &routine, &data->phils_arr[i]);
		pthread_detach(data->phils_arr[i].philo);
	}
	pthread_create(&data->life_monitor, NULL, &life_monitoring, data);
	if (meal_num_opt(data))
		pthread_create(&data->meals_monitor, NULL, &meals_monitoring, data);
}

void	*routine(void *phil_data)
{
	t_philo	*p_d;

	p_d = (t_philo *)phil_data;
	if (p_d->philo_id % 2 == 0)
		ft_usleep(p_d->data->tt_eat / 2);
	while (g_phil_state(p_d) != DEAD && g_phil_state(p_d) != FULL)
	{
		if (eat(p_d) == 1)
			break ;
		if (p_sleep(p_d) == 1)
			break ;
		if (think(p_d) == 1)
			break ;
	}
	return (NULL);
}

void	*life_monitoring(void *data)
{
	int	i;
	t_data	*d;
	t_philo	*philos;
	int		p_num;

	d = (t_data*)data;
	philos = d->phils_arr;
	p_num = d->phils_num;
	i = -1;
	while (++i < p_num && g_iter(d))
	{
		if (rip(&philos[i]) && g_iter(d))
		{
			print_msg(&philos[i], DIED);
			set_iter(d, false);
			let_em_know(d);
			break ;
		}
		if (i == p_num - 1)
			i = -1;
	}
	return (NULL);
}

void	*meals_monitoring(void *data)
{
	int	i;
	t_data	*d;
	t_philo	*philos;
	int		p_num;

	i = -1;
	d = (t_data *)data;
	philos = d->phils_arr;
	p_num = d->phils_num;
	while (++i < p_num && g_iter(d))
	{
		if (g_meals_eaten(&philos[i]) >=  d->meals_num)
			set_phil_state(&philos[i], FULL);
		else
			i = i - 1;
	}
	if (g_iter(d))
		set_iter(d, false);
	return (NULL);
	
}
