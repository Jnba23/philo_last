/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:49:07 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 10:38:28 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	rip(t_philo *p_d)
{
	bool	res;

	if (!g_iter(p_d->data))
		return (0);
	res = false;
	if (get_current_time() - g_last_m_t(p_d) >= p_d->data->tt_die
		&& g_phil_state(p_d) != EATING)
	{
		pthread_mutex_lock(&p_d->mut_phil_state);
		p_d->phil_state = DEAD;
		pthread_mutex_unlock(&p_d->mut_phil_state);
		res = true;
		pthread_mutex_lock(&p_d->data->mut_iter);
		p_d->data->iter = false;
		pthread_mutex_unlock(&p_d->data->mut_iter);
	}
	return (res);
}

void	let_em_know(t_data *data)
{
	t_philo	*philos;
	int		p_num;
	int		i;

	philos = data->phils_arr;
	p_num = data->phils_num;
	i = -1;
	while (++i < p_num)
	{
		pthread_mutex_lock(&data->phils_arr[i].mut_phil_state);
		philos[i].phil_state = DEAD;
		pthread_mutex_unlock(&data->phils_arr[i].mut_phil_state);
	}
}

void	join_monitors(t_data *data)
{
	if (meal_num_opt(data))
		pthread_join(data->meals_monitor, NULL);
	pthread_join(data->life_monitor, NULL);
}
