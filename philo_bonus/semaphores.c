/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 04:59:16 by asayad            #+#    #+#             */
/*   Updated: 2024/07/29 20:30:18 by asayad           ###   ########.fr       */
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
	// data->sem_end = sem_open("/sem_end", O_CREAT, 644, 1);
	// if (data->sem_end == SEM_FAILED)
	// 	return (perror("sem error"), 1);
	// unlink_philos_sem(data);
	return (0);
}

// void	unlink_philos_sem(t_data *data)
// {
// 	int		i;
// 	char	*name;

// 	i = 0;
// 	while (i < data->phils_num)
// 	{
// 		name = ft_strjoin("/sem_philo_", ft_itoa(i + 1));
// 		unlink(name);
// 		free(name);
// 		i++;
// 	}
// }