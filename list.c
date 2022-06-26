/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:55:02 by orandan           #+#    #+#             */
/*   Updated: 2022/06/26 11:10:48 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	*ft_checkarg(int argc, char **argv)
{
	long int	*a;
	int			i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (0);
	a = malloc(sizeof(long int) * argc);
	if (!a)
		return (0);
	while (*++argv)
	{
		a[i] = ft_argtoi(*argv);
		if (a[i++] == 0)
			return (0);
	}
	a[++i] = 0;
	return (a);
}

t_phil	*add_t_phil(t_phil *head, int i, long int *info)
{
	t_phil	*new_n;

	new_n = malloc(sizeof(t_phil));
	if (!(new_n))
		return (0); 
	if (!(head))
		new_n->nxt = NULL;
	else
    	new_n->nxt = head;
	new_n->n_ph = i + 1;
	new_n->t_d = info[1];
	new_n->t_l = info[1];
	new_n->t_e = info[2];
	new_n->t_s = info[3];
	new_n->n_e = info[4];
	new_n->dead = 0;
	pthread_mutex_init(&new_n->frk, NULL);
	return (new_n);
}

t_phil	*ft_llist(int size, long int *info)
{
	int		i;
	t_phil	*head;

	i = 0;
	head = NULL;
	while (--size + 1)
	{
		head = add_t_phil(head, size, info);
		if (!head)
		{
			free(info); // free
			return (0);
		}
	}
	free(info);
	return (head);
}

t_phil	*ft_phil_list(int argc, char **argv)
{
	t_phil		*t_lst_ph;
	t_phil		*tmp_circle;
	long int	*a;

	a = ft_checkarg(argc, argv);
	if (!a)
		return (0);
	t_lst_ph = ft_llist(a[0], a);
	tmp_circle = t_lst_ph;
	while (t_lst_ph->nxt != NULL)
		t_lst_ph = t_lst_ph->nxt;
	t_lst_ph->nxt = &(*tmp_circle);
	t_lst_ph = t_lst_ph->nxt;
	return (t_lst_ph);
}
