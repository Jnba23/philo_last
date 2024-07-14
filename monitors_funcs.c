/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:49:07 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 19:11:07 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	rip(t_philo *p_d)
{
	bool	res;

	res = false;
	if (get_current_time() - g_last_m_t(p_d) >= p_d->data->tt_die
		&& g_phil_state(p_d) != EATING)
	{
		update_phil_state(p_d, DEAD);
		res = true;
	}
	return (res);
}

void	let_em_know(t_data *data)
{
	t_philo *philos;
	int		p_num;
	int		i;

	philos = data->phils_arr;
	p_num = data->phils_num;
	i = -1;
	while (++i < p_num)
		set_phil_state(&philos[i], DEAD);
}

void	join_monitors(t_data *data)
{
	// int	i;

	// i = -1;
	// while (++i)
	// 	pthread_join(data->phils_arr[i].philo, NULL);
	pthread_join(data->life_monitor, NULL);
	if (meal_num_opt(data))
		pthread_join(data->meals_monitor, NULL);
}