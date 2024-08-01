/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:31:53 by asayad            #+#    #+#             */
/*   Updated: 2024/08/01 11:32:22 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 6 || ac == 5)
	{
		if (check_args(ac, av) == 1)
			return (write(2, "Incorrect args ! \n", 19), 1);
		if (init_data(&data, ac, av) == 1)
			return (1);
		philo(&data);
		check_philo_exit(&data);
		free_ressources(&data);
	}
	exit(0);
}
