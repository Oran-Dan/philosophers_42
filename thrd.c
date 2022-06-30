/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:33:04 by orandan           #+#    #+#             */
/*   Updated: 2022/06/29 22:06:42 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_phil	*ph;

	ph = (t_phil *)arg;
	while (!ph->dead)// && ph->n_e)
	{
		ft_print(ph, 1);
		pthread_mutex_lock(&(ph->frk));
		ft_print(ph, 2);
		pthread_mutex_lock(&((ph->nxt)->frk));
		ft_print(ph, 2);
		ft_print(ph, 3);
		ph->t_l = get_time() - ph->strt + ph->t_d;
		ft_msleep(ph->t_e);
		ft_print(ph, 4);
		pthread_mutex_unlock(&((ph->nxt)->frk));
		pthread_mutex_unlock(&(ph->frk));
		ft_msleep(ph->t_s);
	}
	return (NULL);
}

int	meal_check(t_phil *ph)
{
	t_phil	*tmp;

	tmp = ph;
	while (ph->nxt != tmp)
	{
		if (ph->n_e)
			return (1);
		ph = ph->nxt;
	}
	if (ph->n_e)
		return (1);	
	return (0);	
}

void	*ph_manager(void *arg)
{
	t_phil	*ph;
	t_phil	*tmp;

	ph = (t_phil *)arg;
	while (get_time() - ph->strt < ph->t_l && meal_check(ph))
		ph = ph->nxt;
	pthread_mutex_lock(ph->act);
	if (!meal_check(ph))
		printf("Everyone has eaten sufficiently\n");
	else
	{
		ph->dead = get_time() - ph->strt;
		printf("%li	%i died\n", ph->dead, ph->n_ph);
	}
	ph = ph->nxt;
	tmp = ph;
	while (ph->nxt != tmp)
	{
		ph->dead = 1;
		ph = ph->nxt;
	}
//	}
	return (NULL);
}

void	pthrd_create(t_phil *ph) //int argc
{
	pthread_mutex_t	act;
	pthread_t		manager;
	t_phil			*tmp;
	
	tmp = ph;
	pthread_mutex_init(&act, NULL);
	while (ph->nxt != tmp)
	{
		ph->strt = get_time();
		ph->act = &act;
		pthread_create(&ph->thrd, NULL, &routine, ph);
		ph = ph->nxt;
	}
	ph->strt = get_time();
	ph->act = &act;
	pthread_create(&ph->thrd, NULL, &routine, ph);	
	pthread_create(&manager, NULL, &ph_manager, ph);
	pthrd_join(ph);
	pthread_mutex_unlock(ph->act);
	pthread_join(manager, NULL);
}

void	pthrd_join(t_phil *ph)
{
	t_phil	*tmp;

	tmp = ph;
	while (ph->nxt != tmp)
	{	
		pthread_join(ph->thrd, NULL);
		ph = ph->nxt;
	}
	if (ph != ph->nxt)
		pthread_join(ph->thrd, NULL);
}
