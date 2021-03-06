/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:46:25 by hng          #+#    #+#             */
/*   Updated: 2019/11/26 10:46:25 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*format_data_i(char *d, t_params p, int neg)
{
	char	*r;
	int		i;

	r = ft_strdup(d);
	free(d);
	if (ft_strlen(d) != 0)
	{
		while (p.hpoint && p.point > ft_strlen(r))
			r = char_join_and_free(r, '0');
		r = p.hpoint && neg < 0 ? char_join_and_free(r, '-') : r;
	}
	r = (!p.hzero || p.zero <= ft_strlen(r)) && !p.hpoint && neg < 0 ?
			char_join_and_free(r, '-') : r;
	while (p.hzero && p.zero > ft_strlen(r))
		r = char_join_and_free(r, p.hpoint ? ' ' : '0');
	r[0] = r[0] == '0' && neg < 0 ? '-' : r[0];
	while (p.hhyphen && p.hyphen > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width > 0 && p.width > ft_strlen(r))
		r = char_join_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width < 0 && -p.width > ft_strlen(r))
		r = join_char_and_free(r, ' ');
	return (r);
}

int			parse_i(const char *format, va_list a)
{
	int			data;
	char		*result;
	t_params	p;
	int			i;

	i = 0;
	p = read_params(format + 1, 'i', a);
	update_params(&p, 'i');
	data = va_arg(a, int);
	if (data == 0 && p.point == 0 && p.hpoint)
		result = ft_strdup("");
	else
		result = vo_itoa(data);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'i');
	}
	result = format_data_i(result, p, data);
	i = ft_strlen(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
