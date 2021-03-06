/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:02:18 by hng          #+#    #+#             */
/*   Updated: 2021/03/29 13:02:18 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void		display_message_one(unsigned long timestamp, int id, char *msg)
{
	if (g_discard == 0)
		return ;
	if (pthread_mutex_lock(&g_write_lock) != 0)
		return ;
	printf("%ld %d %s\n", timestamp, id + 1, msg);
	if (pthread_mutex_unlock(&g_write_lock) != 0)
		return ;
}
