/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/18 10:25:35 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep(t_philo *p_d)
{
	pthread_mutex_lock(&p_d->mut_phil_state);
	p_d->phil_state = SLEEPING;
	pthread_mutex_unlock(&p_d->mut_phil_state);
	print_msg(p_d, SLEEP);
	ft_usleep(p_d->data->tt_sleep);
}

int	think(t_philo *p_d)
{
	pthread_mutex_lock(&p_d->mut_phil_state);
	print_msg(p_d, THINK);
	p_d->phil_state = THINKING;
	pthread_mutex_unlock(&p_d->mut_phil_state);
	return (0);
}
