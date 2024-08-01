/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:59:16 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 15:46:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_semaphores(t_data *data)
{
	int		i;

	i = 0;
	sem_unlink("/forks");
	sem_unlink("/sem_stdout");
	sem_unlink("/sem_end");
	data->forks = sem_open("/forks", O_CREAT, 644, data->phils_num);
	if (data->forks == SEM_FAILED)
		return (perror("sem error"), 1);
	data->sem_stdout = sem_open("/sem_stdout", O_CREAT, 644, 1);
	if (data->sem_stdout == SEM_FAILED)
		return (perror("sem error"), 1);
	return (0);
}
