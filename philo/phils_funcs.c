/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/18 15:37:43 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *p_d)
{
	pick_up_forks(p_d);
	pthread_mutex_lock(&p_d->mut_phil_state);
	p_d->phil_state = EATING;
	pthread_mutex_unlock(&p_d->mut_phil_state);
	print_msg(p_d, EAT);
	pthread_mutex_lock(&p_d->data->mut_last_meal);
	p_d->last_meal = get_current_time();
	pthread_mutex_unlock(&p_d->data->mut_last_meal);
	pthread_mutex_lock(&p_d->data->mut_meals_eaten);
	p_d->meals_eaten++;
	pthread_mutex_unlock(&p_d->data->mut_meals_eaten);
	ft_usleep(p_d->data->tt_eat);
	put_down_forks(p_d);
}

void	pick_up_forks(t_philo *p_d)
{
	pthread_mutex_lock(p_d->l_fork);
	print_msg(p_d, FORK_TAKEN);
	pthread_mutex_lock(p_d->r_fork);
	print_msg(p_d, FORK_TAKEN);
}

void	put_down_forks(t_philo *p_d)
{
	pthread_mutex_unlock(p_d->l_fork);
	pthread_mutex_unlock(p_d->r_fork);
}

// void	increment_meals_eaten(t_philo *p_d)
// {
// 	pthread_mutex_lock(&p_d->data->mut_meals_eaten);
// 	p_d->meals_eaten++;
// 	pthread_mutex_unlock(&p_d->data->mut_meals_eaten);
// }

// void	update_last_meal(t_philo *p_d)
// {
// 	pthread_mutex_lock(&p_d->data->mut_last_meal);
// 	p_d->last_meal = get_current_time();
// 	pthread_mutex_unlock(&p_d->data->mut_last_meal);
// }

// void	update_phil_state(t_philo *p_d, t_state state)
// {
// 	// pthread_mutex_lock(&p_d->data->mut_phil_state);
// 	p_d->phil_state = state;
// 	// pthread_mutex_unlock(&p_d->data->mut_phil_state);
// }