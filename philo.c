/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:31 by odan              #+#    #+#             */
/*   Updated: 2022/06/26 13:55:28 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_phil	*t_lst_ph;

	long int	i = get_time();
//	printf("%li\n", i);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);
	ft_msleep(1);

	printf("%li\n", get_time() - i);

	t_lst_ph = ft_phil_list(argc, argv);
	if (!t_lst_ph)
		return (ft_error());
	pthrd_create(t_lst_ph);
	pthrd_join(t_lst_ph);
	return (0);
}
