/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:20:04 by asayad            #+#    #+#             */
/*   Updated: 2024/07/13 18:08:05 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h> //malloc
#include <sys/time.h> //gettimeofday
#include <unistd.h> //write ,sleep, usleep
#include <stdio.h> //printf
#include <limits.h> //Macros
#include <stdbool.h> //Macros

/* Colors */

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"

/* States */

#define FORK_TAKEN "has taken a fork\n"
#define EAT "is eating\n"
#define SLEEP "is sleeping\n"
#define THINK "is thinking\n"
#define DIED "died\n"

typedef enum philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	STANDBY = 5
} t_state;

typedef struct philo
{
	pthread_t			philo;
	int					philo_id;
	u_int64_t			last_meal; // initialize to current time
	int					meals_eaten;
	t_state				phil_state;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
			/* mutexes */
	pthread_mutex_t		mut_meals_eaten;
	pthread_mutex_t		mut_phil_state;
	pthread_mutex_t		mut_last_meal;
			/* end */
	struct data			*data;
} t_philo;

typedef struct data
{
	int					phils_num;
	u_int64_t			start_time;
	u_int64_t			tt_die;
	u_int64_t			tt_eat; 
	u_int64_t			tt_sleep;
	int					meals_num;
	t_philo				*phils_arr;
	pthread_mutex_t		*forks_arr;
		/* setters mutexes */
	pthread_mutex_t		print_lock;
	pthread_mutex_t		mut_iter;
			/* end */
	pthread_t			life_monitor;
	pthread_t			meals_monitor;
	bool				iter;
} t_data;

/*	Parsing	*/
int			digits_only(char *s);
int			check_args(int ac, char **av);
long long	ft_atoi(char *str);

/*	Initializations	*/
int			malloc_arrs(t_data *data);
int			init_data(t_data *data, int ac, char **av);
int			init_forks(t_data *data);
int			init_philos(t_data *data);

/*	Utils	*/
u_int64_t	get_current_time();
void		ft_usleep(u_int64_t tt_sleep);
bool		meal_num_opt(t_data *data);
void		free_ressources(t_data *data);

/*	getters */
t_state		g_phil_state(t_philo *data);
u_int64_t	g_start_t(t_philo *p_d);
u_int64_t	g_last_m_t(t_philo *p_d);
bool		g_iter(t_data	*data);
int			g_meals_eaten(t_philo *p_d);


/*	setters */
void		set_phil_state(t_philo *p_d, t_state state);
void		print_msg(t_philo *p_d, char *msg);
void		set_iter(t_data	*data, bool status);

/*	phils funcs */
int			eat(t_philo *p_d);
int			pick_up_forks(t_philo *p_d);
void		increment_meals_eaten(t_philo *p_d);
void		update_last_meal(t_philo *p_d);
int			put_down_forks(t_philo *p_d);
void		update_phil_state(t_philo *p_d, t_state state);
int			think(t_philo *p_d);
int			p_sleep(t_philo *p_d);

/*	monitors funcs	*/
bool		rip(t_philo *p_d);
void		*life_monitoring(void *args);
void		*meals_monitoring(void *args);
void		*routine(void *args);
void		run_threads(t_data *data);
void		let_em_know(t_data *data);
void		join_monitors(t_data *data);
#endif
/* while (infinite)	*/
/* 	check_death_flag	*/
/*	if (death_flag == TRUE) */
/*	END routine */
/*	else	*/
/*	RUN routine	*/
/*	see how to update the time and see the formula of each time : eat, sleep, die..*/

// use a mutex for each var accessed and modified by many threads, 
// detach threads && join monitor (no need for bool), no communication between processes