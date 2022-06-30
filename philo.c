/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:31 by odan              #+#    #+#             */
/*   Updated: 2022/06/27 10:50:56 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_phil	*t_lst_ph;

	t_lst_ph = ft_phil_list(argc, argv);
	if (!t_lst_ph)
		return (ft_error());
	pthrd_create(t_lst_ph);
	pthrd_join(t_lst_ph);
	return (0);
}
