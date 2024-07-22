/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:37:04 by asayad            #+#    #+#             */
/*   Updated: 2024/07/18 15:42:26 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phils_num)
	{
		if (pthread_mutex_init(&data->forks_arr[i], NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->phils_arr[i].mut_phil_state, NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}
