/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:24:44 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 00:04:43 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phils_num)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == 0)
			run_philo(&data->philos[i]);
	}
}

void	run_philo(t_philo *p_data)	
{
	t_data	*data;
	
	
	data = p_data->data;
	if (p_data->philo_id % 2 == 0)
		ft_usleep(10);
	if (pthread_create(&p_data->monitor, NULL, &routine_mon, (void *)p_data))	
		exit (2); //kill processes
	pthread_detach(p_data->monitor);
	while (1)
	{
		// if (p_data->dead)
		// {
		// printf("philo : %d\n", p_data->philo_id);
		// printf("sem value : %d\n", sem_getvalue(data->sem_stdout, NULL));
		// 	if (sem_wait(data->sem_end) == -1)
		// 		puts("ERROR sem_end");
		// }
		take_forks(p_data);
		eat(p_data);
		if (data->meals_num > 0)
	{
			if (p_data->meals_eaten == data->meals_num)
			{
				// p_data->state = FULL;
				printf("Im %d and I ate %d\n", p_data->philo_id, p_data->meals_eaten);	
				exit (42);
			}
	}
		p_sleep(p_data);
		think(p_data);
	}
}

void	*routine_mon(void *p_d)
{
	t_philo	*p_data;
	t_data	*data;

	p_data = (t_philo *)p_d;
	data = p_data->data;
	while (1)
	{
		if (get_current_time() - p_data->last_meal > data->tt_die)
		{
			p_data->state = DEAD;
			print_msg(p_data, DIED);
			exit (21);
		}
	}
	return (NULL);
}

void	kill_processes(t_data *data, int p_id)
{
	int		i;
	t_philo	*philos;

	(void)p_id;
	i = 0;
	philos = data->philos;
	while (i < data->phils_num)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
}
