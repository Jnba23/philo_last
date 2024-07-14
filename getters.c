/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:13 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 19:11:03 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	g_phil_state(t_philo *data)
{
    t_state	state;

	pthread_mutex_lock(&data->mut_phil_state);
	state = data->phil_state;
	pthread_mutex_unlock(&data->mut_phil_state);
	return (state);
}

u_int64_t	g_start_t(t_philo *p_d)
{
	u_int64_t	t;

	t = p_d->data->start_time;
	return (t);
}

u_int64_t	g_last_m_t(t_philo *p_d)
{
	u_int64_t	l_m_t;

	pthread_mutex_lock(&p_d->mut_last_meal);
	l_m_t = p_d->last_meal;
	pthread_mutex_unlock(&p_d->mut_last_meal);
	return (l_m_t);
}

bool	g_iter(t_data	*data)
{
	bool	status;

	pthread_mutex_lock(&data->mut_iter);
	status = data->iter;
	pthread_mutex_unlock(&data->mut_iter);
	return (status);
}

int	g_meals_eaten(t_philo *p_d)
{
	int	m_e;

	pthread_mutex_lock(&p_d->mut_meals_eaten);
	m_e = p_d->meals_eaten;
	pthread_mutex_unlock(&p_d->mut_meals_eaten);
	return (m_e);
}