/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:53:26 by odan              #+#    #+#             */
/*   Updated: 2022/06/29 09:13:07 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil		t_phil;
typedef struct timeval		t_clck;
typedef unsigned long int	t_uli;

struct s_phil
{
	int				n_ph;
	int				t_d;
	int				t_e;
	int				t_s;
	int				n_e;
	t_uli			dead;
	t_uli			t_l;
	t_uli			strt;	
	t_phil			*nxt;
	pthread_t		thrd;
	pthread_mutex_t	frk;
	pthread_mutex_t	*act;
};

int			ft_error(void);
t_uli		get_time(void);
int			ft_argtoi(const char *str);
long int	*ft_checkarg(int argc, char **argv);
void		ft_msleep(t_uli tme);
void		ft_print(t_phil *ph, int i);
t_phil		*add_t_phil(t_phil *head, int i, long int *info, pthread_mutex_t act);
t_phil		*ft_llist(int size, long int *info);
t_phil		*ft_phil_list(int argc, char **argv);
void		*routine(void *arg);
void		*ph_manager(void *arg);
void		pthrd_create(t_phil *t_lst_ph);
void		pthrd_join(t_phil *t_lst_ph);

#endif
