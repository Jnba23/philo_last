/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:31:53 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 00:09:24 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	int		e_val;
	int		full_phil_num;

	full_phil_num = 0;
	i = 0;
	if (ac == 6 || ac == 5)
	{
		if (check_args(ac, av) == 1)
			return (write(2, "Incorrect args ! \n", 19), 1);
		if (init_data(&data, ac, av) == 1)
			return (1);
		philo(&data);
		while (1)
		{
			if (waitpid(data.philos[i].pid, &e_val, WNOHANG) != 0)
			{
				if (WIFEXITED(e_val) && WEXITSTATUS(e_val) == 21)
					return (kill_processes(&data, i + 1), free_ressources(&data), 1);
				else if (WIFEXITED(e_val) && WEXITSTATUS(e_val) == 42)
				{
					// printf("%d\n", full_phil_num);
					full_phil_num++;
					if (full_phil_num == data.phils_num)
						break;
				}
			}
			i++;
			if (i == data.phils_num)
				i = 0;
		}
		free_ressources(&data);
	}
	exit(0);
}
