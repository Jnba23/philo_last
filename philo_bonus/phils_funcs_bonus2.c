/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:24:44 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 11:24:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *p_data)
{
	t_data	*data;

	data = p_data->data;
	sem_wait(data->forks);
	print_msg(p_data, FORK_TAKEN, 0);
	if (data->phils_num == 1)
	{
		ft_usleep(data->tt_die);
		sem_wait(data->sem_stdout);
		if (data->phils_num == 1)
			sem_post(data->sem_stdout);
	}
	sem_wait(data->forks);
	print_msg(p_data, FORK_TAKEN, 0);
}

void	eat(t_philo *p_data)
{
	t_data	*data;

	data = p_data->data;
	print_msg(p_data, EAT, 0);
	p_data->last_meal = get_current_time();
	p_data->meals_eaten++;
	ft_usleep(data->tt_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	p_sleep(t_philo *p_data)
{
	t_data	*data;

	data = p_data->data;
	print_msg(p_data, SLEEP, 0);
	ft_usleep(data->tt_sleep);
}

void	think(t_philo *p_data)
{
	print_msg(p_data, THINK, 0);
}

void	free_ressources(t_data *data)
{
	sem_unlink("/sem_stdout");
	sem_unlink("/forks");
	sem_unlink("/sem_end");
	sem_close(data->forks);
	sem_close(data->sem_stdout);
	if (data->philos)
		free(data->philos);
	while (waitpid(-1, NULL, 0) > 0)
		;
}
