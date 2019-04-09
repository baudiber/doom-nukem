/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:35 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 15:09:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static bool			check_tier(t_data *data)
{
	int				i;
	int				ret;

	i = 0;
	ret = (data->stage) ? 0 : 1;
	while (ret == 0 && data->stage[i])
		i++;
	if (data->tier_size == 0)
		data->tier_size = i;
	if (i != data->tier_size)
		ret = 1;
	return (ret == 0) ? true : false;
}

void				parse_tier(t_data *data)
{
	int				i;

	i = 0;
	while (data->tier[i] && data->tier_ind < 5)
	{
		if (!(data->stage = ft_strsplit(data->tier[i], '\n')))
			parse_quit(data, 1, ERR_1);
		if (!check_tier(data))
			parse_quit(data, 4, ERR_4);
		parse_stage(data);
		data->tier_ind++;
		i++;
	}
	(data->stage) ? ft_str_tabdel(&data->stage) : 0;
	(data->tier) ? ft_str_tabdel(&data->tier) : 0;
}
