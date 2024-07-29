/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:45:27 by asayad            #+#    #+#             */
/*   Updated: 2024/07/29 20:30:52 by asayad           ###   ########.fr       */
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

// static int	size(int n)
// {
// 	int	size;

// 	size = 1;
// 	while (n / 10 != 0)
// 	{
// 		n = n / 10;
// 		size++;
// 	}
// 	return (size);
// }

// static void	negnum(char *s, int *n)
// {
// 	if (*n < 0)
// 	{
// 		s[0] = '-';
// 		*n = -1 * (*n);
// 	}
// }

// char	*ft_itoa(int n)
// {
// 	char	*s;
// 	int		j;

// 	// if (n == -2147483648)
// 	// 	return (ft_strdup("-2147483648"));
// 	j = size(n) + (n < 0);
// 	s = NULL;
// 	s = ft_calloc(j + 1, 1);
// 	if (!s)
// 		return (NULL);
// 	if (n < 0)
// 		negnum(s, &n);
// 	while (n / 10 != 0)
// 	{
// 		s[--j] = n % 10 + 48;
// 		n = n / 10;
// 	}
// 	s[j - 1] = n + 48;
// 	return (s);
// }

int	print_msg(t_philo *p_data, char *msg)
{
	u_int64_t	time;
	t_data		*data;

	data = p_data->data;
	time = get_current_time() - data->start_time;
	if (sem_wait(data->sem_stdout) == -1)
		puts("ERROR SEM");
	printf("%llu %d %s", time, p_data->philo_id, msg);
	if (p_data->state != DEAD)
	{
		if (sem_post(data->sem_stdout) == -1)
			puts("ERROR SEM");
	}
	return (0);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*s;
// 	size_t	c;

// 	c = count * size;
// 	if (size != 0 && c / size != count)
// 		return (NULL);
// 	s = (char *)malloc(count * (size));
// 	if (!s)
// 		return (NULL);
// 	s = ft_memset(s, 0, count * size);
// 	return ((void *)s);
// }

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t	i;
// 	char	*ptr;

// 	ptr = (char *) b;
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = (char) c;
// 		i++;
// 	}
// 	return ((void *)b);
// }
