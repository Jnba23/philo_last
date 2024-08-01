/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs_bonus3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:24:44 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 16:53:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_philo_exit(t_data *data)
{
	int	i;
	int	e_val;
	int	full_phil_num;

	i = 0;
	full_phil_num = 0;
	while (1)
	{
		if (waitpid(data->philos[i].pid, &e_val, WNOHANG) != 0)
		{
			if (WIFEXITED(e_val) && WEXITSTATUS(e_val) == 21)
				return (kill_processes(data, i + 1));
			else if (WIFEXITED(e_val) && WEXITSTATUS(e_val) == 42)
			{
				full_phil_num++;
				if (full_phil_num == data->phils_num)
					break ;
			}
		}
		i++;
		if (i == data->phils_num)
			i = 0;
	}
}
