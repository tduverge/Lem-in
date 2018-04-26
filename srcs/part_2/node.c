/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   node.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:53 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:53 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

t_room		node_room(t_list *lst)
{
	return (*((*(t_node *)lst->content).room));
}

int			*node_path(t_list *lst)
{
	return ((*(t_node *)lst->content).path);
}

t_node		*new_node(int *path, t_room *room, t_node *next)
{
	t_node		*new;

	new = (t_node *)ft_memalloc(sizeof(t_node));
	new->path = path;
	new->room = room;
	new->next = next;
	return (new);
}

void		free_node(t_node *nodes_q)
{
	free(nodes_q->path);
	nodes_q->next = NULL;
	free(nodes_q);
}

void		ft_del_node(t_node *nodes_q)
{
	if (!nodes_q)
		return ;
	if (nodes_q->next)
		ft_del_node(nodes_q->next);
	free_node(nodes_q);
}
