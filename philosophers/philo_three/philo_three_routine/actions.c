/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 15:54:34 by hng          #+#    #+#             */
/*   Updated: 2021/03/89 15:54:34 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	grab_fork(t_philo_data *pd)
{
	sem_wait(g_sem_forks);
	if (pd->status == DEAD)
		return ;
	display_message_three(get_time_stamp(), pd->id, "has taken a fork");
	sem_wait(g_sem_forks);
	if (pd->status == DEAD)
		return ;
	display_message_three(get_time_stamp(), pd->id, "has taken a fork");
}

void		release_forks(void)
{
	sem_post(g_sem_forks);
	sem_post(g_sem_forks);
}

void		action_eat_three(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	grab_fork(pd);
	if (pd->status == DEAD)
		return ;
	pd->meal_count++;
	display_message_three(get_time_stamp(), pd->id, "is eating");
	pd->last_lunch = get_time_stamp();
	wait_and_check(pd, g_time_to_eat);
	release_forks();
}

void		action_sleep_three(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	display_message_three(get_time_stamp(), pd->id, "is sleeping");
	wait_and_check(pd, g_time_to_sleep);
}

void		action_think_three(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	display_message_three(get_time_stamp(), pd->id, "is thinking");
}
