/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_funcs_bonus3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:24:44 by asayad            #+#    #+#             */
/*   Updated: 2024/07/29 20:33:11 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_philos(t_data *data)
{
	int	i;
	int	e_val;

	i = 0;
	while (1)
		{
			while (i < data->phils_num)
			{
				waitpid(data->philos[i].pid, &e_val, WNOHANG);
				if (WIFEXITED(e_val))
				{
					if (WEXITSTATUS(e_val) == 2)
						return (kill_processes(data, data->philos[i - 1].philo_id), free_ressources(data));
					if (WEXITSTATUS(e_val) == 1)
					{
						i++;
						if (i == data->phils_num)
							i = 0;
						continue ;
					}
					i++;
					if (i == data->phils_num)
						i = 0;
				}
			}
		}
}
