/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 07:21:51 by hng          #+#    #+#             */
/*   Updated: 2020/01/01 07:21:51 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	special_malloc(void *item, int size, int count)
{
	item = malloc(size * count);
	if (item == 0)
		return (0);
	return (1);
}
