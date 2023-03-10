/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:48:37 by muraler           #+#    #+#             */
/*   Updated: 2022/12/17 11:05:08 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	free_all_data(t_data **all_data)
{
	free((*all_data)->forks_list);
	free((*all_data)->chats_list);
	free((*all_data)->dead_checker);
	free((*all_data)->pthread_list);
	free((*all_data)->philo_list);
	free(*all_data);
}

int	join_philo_thread(t_data *all_data)
{
	int	i;

	i = 0;
	while (i < all_data->input_param.count)
	{
		if (pthread_join(all_data->pthread_list[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	destroy_mutexes(t_data *all_data)
{
	int	i;

	i = 0;
	while (i < all_data->input_param.count)
	{
		pthread_mutex_destroy(&all_data->forks_list[i]);
		pthread_mutex_destroy(&all_data->chats_list[i]);
		pthread_mutex_destroy(&all_data->dead_checker[i]);
		i++;
	}
	pthread_mutex_destroy(&all_data->print_fork);
	pthread_mutex_destroy(&all_data->dead_man_check);
}
