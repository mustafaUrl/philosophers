/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muraler <muraler@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:53:24 by muraler           #+#    #+#             */
/*   Updated: 2022/12/17 10:57:50 by muraler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	is_positive_num(int num_int, char *num_str)
{
	char	*tmp_str;
	size_t	len[2];

	if (num_int <= 0)
		return (0);
	tmp_str = ft_itoa(num_int);
	len[0] = ft_strlen(tmp_str);
	len[1] = ft_strlen(num_str);
	if (len[0] != len[1])
		return (0);
	if (ft_strncmp(tmp_str, num_str, len[0]))
	{
		free(tmp_str);
		return (0);
	}
	free(tmp_str);
	return (1);
}

t_param	init_input(int argc, char **argv)
{
	t_param	input;

	input.count = ft_atoi(argv[1]);
	input.time_to_die = ft_atoi(argv[2]);
	input.time_to_eat = ft_atoi(argv[3]);
	input.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input.philo_must_eat = ft_atoi(argv[5]);
	else
		input.philo_must_eat = -1;
	if (!is_positive_num(input.count, argv[1])
		|| !is_positive_num(input.time_to_die, argv[2])
		|| !is_positive_num(input.time_to_eat, argv[3])
		|| !is_positive_num(input.time_to_sleep, argv[4])
		|| (argc == 6 && !is_positive_num(input.philo_must_eat, argv[5])))
		input.count = 0;
	return (input);
}
