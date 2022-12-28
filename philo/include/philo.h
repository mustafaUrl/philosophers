/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:50:37 by muraler           #+#    #+#             */
/*   Updated: 2022/12/17 11:05:04 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_param
{
	int				count;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				philo_must_eat;
}	t_param;

typedef struct s_philo
{
	int				id;
	int				state;
	int				time_eat;
	unsigned long	last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*check_hunger;
	void			*all_data;
}	t_philo;

typedef struct s_data
{
	pthread_t		*pthread_list;
	pthread_t		monitor_thread;
	pthread_mutex_t	*forks_list;
	pthread_mutex_t	*chats_list;
	pthread_mutex_t	*dead_checker;
	t_philo			*philo_list;
	t_param			input_param;
	pthread_mutex_t	print_fork;
	pthread_mutex_t	dead_man_check;
	unsigned long	start_time;
	int				dead_man;
	int				must_eat_counter;
}	t_data;

t_param			init_input(int argc, char **argv);
int				init_all_data(t_data *all_data);
void			*monitor(void	*param);
int				start_philo(t_data	*all_data);
unsigned long	get_time(void);
void			philo_print(t_data *all_data, int id, char *msg);
int				error(char *str);
void			destroy_mutexes(t_data *all_data);
int				join_philo_thread(t_data *all_data);
void			free_all_data(t_data **all_data);
void			philo_print(t_data *all_data, int id, char *msg);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				is_some_dead(t_philo *philo);
void			philo_eat(t_philo *philo, t_data *all_data);
void			philo_sleep(t_philo *philo, t_data *all_data);

#endif //PHILO_H
