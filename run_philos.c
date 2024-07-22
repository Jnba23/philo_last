/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:07:48 by asayad            #+#    #+#             */
/*   Updated: 2024/07/22 11:29:49 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_threads(t_data *data)
{
	int	i;

	i = -1;
	pthread_create(&data->life_monitor, NULL, &life_monitoring, data);
	if (meal_num_opt(data))
		pthread_create(&data->meals_monitor, NULL, &meals_monitoring, data);
	while (++i < data->phils_num)
	{
		pthread_create(&data->phils_arr[i].philo, NULL,
			&routine, &data->phils_arr[i]);
		pthread_detach(data->phils_arr[i].philo);
	}
}

void	*routine(void *phil_data)
{
	t_philo		*p_d;
	u_int64_t	slow_t;

	p_d = (t_philo *)phil_data;
	slow_t = p_d->data->tt_eat / 2;
	if (p_d->philo_id % 2 == 0)
		ft_usleep(slow_t);
	while (g_phil_state(p_d) != DEAD && g_phil_state(p_d) != FULL)
	{
		eat(p_d);
		if (g_phil_state(p_d) == DEAD)
			break ;
		p_sleep(p_d);
		think(p_d);
	}
	return (NULL);
}

void	*life_monitoring(void *data)
{
	int		i;
	t_data	*d;
	t_philo	*philos;
	int		p_num;

	d = (t_data *)data;
	philos = d->phils_arr;
	p_num = d->phils_num;
	i = -1;
	while (++i < p_num && g_iter(d))
	{
		if (rip(&philos[i]))
		{
			pthread_mutex_lock(&d->mut_print);
			printf("%llu %d died\n",
				get_current_time() - philos[i].last_meal, philos[i].philo_id);
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
	int		i;
	t_data	*d;
	t_philo	*philos;
	int		p_num;

	i = 0;
	d = (t_data *)data;
	philos = d->phils_arr;
	p_num = d->phils_num;
	while (i < p_num)
	{
		if (!g_iter(d))
			break ;
		if (g_meals_eaten(&philos[i]) > d->meals_num)
		{
			pthread_mutex_lock(&philos[i].mut_phil_state);
			philos[i].phil_state = FULL;
			if (i == p_num - 1)
				set_iter(d, false);
			i++;
		}
	}
	return (NULL);
}
