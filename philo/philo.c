/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:49:07 by asayad            #+#    #+#             */
/*   Updated: 2024/07/22 10:35:58 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void f()
{
	system("leaks philo");
}
int	main(int ac, char **av)
{
	// atexit(f);
	t_data	data;
	int		i;

	if (ac == 5 || ac == 6)
	{
		if (check_args(ac, av) == 1)
			return (write(2, "Incorrect args ! \n", 19), 1);
		i = init_data(&data, ac, av);
		if (i == 1)
			return (write(2, "Malloc fail !\n", 15), 1);
		else if (i == 2)
			return (1);
		init_philos(&data);
		i = init_forks(&data);
		if (i == 1)
			return (free_ressources(&data, 0), 1);
		else if (i == 2)
			return (free_ressources(&data, 2), 1);
		run_threads(&data);
		join_monitors(&data);
		return (free_ressources(&data, 1), 0);
	}
	else
		return (write(2, "Too many or not enough args !\n", 31), 1);
}
