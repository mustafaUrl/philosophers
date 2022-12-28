/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:47:48 by muraler           #+#    #+#             */
/*   Updated: 2022/12/17 11:03:17 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_stop(t_data *all_data)
{
	int	on;

	on = 1;
	pthread_mutex_lock(&all_data->dead_man_check);
	if (all_data->must_eat_counter == all_data->input_param.count)
	{
		all_data->dead_man = 1;
		on = 0;
	}
	pthread_mutex_unlock(&all_data->dead_man_check);
	return (on);
}

int	check_dead(t_data *all_data, int index)
{
	int	on;

	on = 1;
	pthread_mutex_lock(&all_data->chats_list[index]);
	if (all_data->philo_list[index].state != 0
		&& get_time() - all_data->philo_list[index].last_eat
		> all_data->input_param.time_to_die)
	{
		philo_print(all_data, index, "died");
		pthread_mutex_lock(&all_data->dead_man_check);
		all_data->dead_man = 1;
		pthread_mutex_unlock(&all_data->dead_man_check);
		on = 0;
	}
	pthread_mutex_unlock(&all_data->chats_list[index]);
	return (on);
}

void	*monitor(void	*param)
{
	t_data	*all_data;
	int		on;
	int		i;

	all_data = (t_data *)param;
	on = 1;
	i = 0;
	while (on)
	{
		while (on && i < all_data->input_param.count)
		{
			on = check_stop(all_data);
			if (on)
				on = check_dead(all_data, i);
			i++;
		}
		i = 0;
	}
	return (NULL);
}
