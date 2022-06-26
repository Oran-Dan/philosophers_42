/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:26 by odan              #+#    #+#             */
/*   Updated: 2022/06/26 13:42:00 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil	t_phil;
typedef struct timeval	clck;
typedef unsigned long int	uli;

struct s_phil
{
	int				n_ph;
	int				t_d;
	int				t_e;
	int				t_s;
	int				n_e;
	uli				dead;
	uli				t_l;
	uli				strt;	
	t_phil			*nxt;
	pthread_t		thrd;
	pthread_mutex_t	frk;
};

int			ft_error(void);
uli			get_time();
int			ft_argtoi(const char *str);
long int	*ft_checkarg(int argc, char **argv);
void		ft_msleep(uli tme);
t_phil		*add_t_phil(t_phil *head, int i, long int *info);
t_phil		*ft_llist(int size, long int *info);
t_phil		*ft_phil_list(int argc, char **argv);
void		*routine(void *arg);
void    	*die(void *arg);
void		pthrd_create(t_phil *t_lst_ph);
void		pthrd_join(t_phil *t_lst_ph);

#endif
