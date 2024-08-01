/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:32:32 by asayad            #+#    #+#             */
/*   Updated: 2024/07/30 17:19:32 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdatomic.h>

# define FORK_TAKEN "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

typedef struct philo
{
	int					philo_id;
	pid_t				pid;		
	_Atomic u_int64_t	last_meal;
	int					meals_eaten;
	pthread_t			monitor;
	struct data			*data;
}	t_philo;

typedef struct data
{
	int			phils_num;
	u_int64_t	tt_die;
	u_int64_t	tt_eat;
	u_int64_t	tt_sleep;
	int			meals_num;
	u_int64_t	start_time;
	sem_t		*forks;
	sem_t		*sem_stdout;
	t_philo		*philos;
			/* end */
}	t_data;

int			check_args(int ac, char **av);
int			digits_only(char *s);
long long	ft_atoi(char *str);
int			init_data(t_data *data, int ac, char **av);
void		init_philos(t_data *data);
int			create_semaphores(t_data *data);
void		philo(t_data *data);
void		run_philo(t_philo *p_data);
void		*routine_mon(void *p_d);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
u_int64_t	get_current_time(void);
void		ft_usleep(u_int64_t tt_sleep);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
void		kill_processes(t_data *data, int p_id);
void		free_ressources(t_data *data);
bool		meal_num_opt(t_data *data);
void		take_forks(t_philo *p_data);
void		eat(t_philo *p_data);
void		p_sleep(t_philo *p_data);
void		think(t_philo *p_data);
int			print_msg(t_philo *p_data, char *msg, int dead);
int			ft_strcmp(char *s1, char *s2);
void		check_philo_exit(t_data *data);
#endif
