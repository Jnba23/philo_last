/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:49:07 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 05:21:41 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (ac == 5 || ac == 6)
	{
		if (check_args(ac, av) == 1)
			return (write(2, "Incorrect args ! \n", 1), 1);
		if (init_data(data, ac, av) == 1)
			return(write(2, "Malloc fail !\n", 15), 1);
		if (init_forks(data) == 1 || init_philos(data) == 1)
			return (free_ressources(data), 1);
		run_threads(data);
		join_monitors(data);
		free_ressources(data);
		return (0);
	}
	else
		return (write(2, "Too many or not enough args !\n", 31), 1);
}
