/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:30:29 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 10:36:13 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *p_d, char *msg)
{
	u_int64_t	time;

	time = get_current_time() - g_start_t(p_d);
	printf("%llu %d %s", time, p_d->philo_id, msg);
}
void	set_iter(t_data *data, bool status)
{
	pthread_mutex_lock(&data->mut_iter);
	data->iter = status;
	pthread_mutex_unlock(&data->mut_iter);
}

void	set_phil_state(t_philo *p_d, t_state state)
{
	pthread_mutex_lock(&p_d->mut_phil_state);
	p_d->phil_state = state;
	pthread_mutex_unlock(&p_d->mut_phil_state);
}