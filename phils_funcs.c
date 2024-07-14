/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 18:09:49 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *p_d)
{
	if (pick_up_forks(p_d) == 1)
		return (1);
	print_msg(p_d, EAT);
	update_phil_state(p_d, EATING);
	ft_usleep(p_d->data->tt_eat);
	update_last_meal(p_d);
	increment_meals_eaten(p_d);
	if (put_down_forks(p_d) == 1)
		return (1);
	return (0);
}
int	pick_up_forks(t_philo *p_d)
{
	if (g_phil_state(p_d) == DEAD)
		return (1);
	pthread_mutex_lock(p_d->l_fork);
	print_msg(p_d, FORK_TAKEN);
	pthread_mutex_lock(p_d->r_fork);
	print_msg(p_d, FORK_TAKEN);
	return (0);
}

void	update_last_meal(t_philo *p_d)
{
	pthread_mutex_lock(&p_d->mut_last_meal);
	p_d->last_meal = get_current_time();
	pthread_mutex_unlock(&p_d->mut_last_meal);
}

void	increment_meals_eaten(t_philo *p_d)
{
	pthread_mutex_lock(&p_d->mut_meals_eaten);
	p_d->meals_eaten++;
	pthread_mutex_unlock(&p_d->mut_meals_eaten);
}

void	update_phil_state(t_philo *p_d, t_state state)
{
	pthread_mutex_lock(&p_d->mut_phil_state);
	p_d->phil_state = state;
	pthread_mutex_unlock(&p_d->mut_phil_state);
}

int	put_down_forks(t_philo *p_d)
{
	if (g_phil_state(p_d) == DEAD)
		return (1);
	pthread_mutex_unlock(p_d->l_fork);
	pthread_mutex_unlock(p_d->r_fork);
	return (0);
}