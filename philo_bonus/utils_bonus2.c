/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:45:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 16:45:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	else
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	j;
	size_t	slen;

	dlen = 0;
	slen = 0;
	j = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (dlen >= dstsize)
		return (dstsize + slen);
	while (j < dstsize - dlen - 1 && src[j])
	{
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = '\0';
	return (dlen + slen);
}

int	print_msg(t_philo *p_data, char *msg, int dead)
{
	u_int64_t	time;
	t_data		*data;

	data = p_data->data;
	time = get_current_time() - data->start_time;
	if (sem_wait(data->sem_stdout) == -1)
		puts("ERROR SEM");
	printf("%llu %d %s", time, p_data->philo_id, msg);
	if (dead == 0)
	{
		if (sem_post(data->sem_stdout) == -1)
			puts("ERROR SEM");
	}
	return (0);
}
