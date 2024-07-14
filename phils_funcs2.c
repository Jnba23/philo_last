/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 17:23:15 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_sleep(t_philo *p_d)
{
	if (g_phil_state(p_d) == DEAD)
		return (1);
	print_msg(p_d, SLEEP);
	update_phil_state(p_d, SLEEPING);
	ft_usleep(p_d->data->tt_sleep);
	return (0);
}

int	think(t_philo *p_d)
{
	if (g_phil_state(p_d) == DEAD)
		return (1);
	print_msg(p_d, THINK);
	update_phil_state(p_d, THINKING);
	return (0);
}
