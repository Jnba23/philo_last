/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:30:29 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 09:44:35 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *p_d, char *msg)
{
	long long	time;

	pthread_mutex_lock(&p_d->data->mut_print);
	time = get_current_time() - g_start_t(p_d);
	printf("%llu %d %s", time, p_d->philo_id, msg);
	pthread_mutex_unlock(&p_d->data->mut_print);
}

void	set_iter(t_data *data, bool status)
{
	pthread_mutex_lock(&data->mut_iter);
	data->iter = status;
	pthread_mutex_unlock(&data->mut_iter);
}
