/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:36 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:39 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

void		ft_print_rooms(t_list *rooms)
{
	t_room		cur_room;

	while (rooms)
	{
		cur_room = room(rooms);
		ft_printf("/*********************\\\n");
		ft_printf("| Name   : %10s |\n", cur_room.name);
		ft_printf("| id     : %10d |\n", cur_room.id);
		ft_printf("| Nb ants: %10d |\n", cur_room.ants);
		ft_printf("| x      : %10d |\n", cur_room.x);
		ft_printf("| y      : %10d |\n", cur_room.y);
		ft_printf("| pos    : %10d |\n", cur_room.pos);
		ft_printf("| visited: %10d |\n", cur_room.visited);
		if (cur_room.links)
			while (cur_room.links)
			{
				ft_printf("| links  : %5s:id%2d |\n",
						cur_room.links->room->name, cur_room.links->room->id);
				cur_room.links = cur_room.links->next;
			}
		ft_printf("\\*********************/\n");
		rooms = rooms->next;
	}
}

void		ft_print_nodes(t_list *nodes_q)
{
	int		i;

	while (nodes_q)
	{
		i = 0;
		ft_printf("Current : %s (id: %d)\n",
				node_room(nodes_q).name, node_room(nodes_q).id);
		ft_printf("Path    : ");
		if (node_path(nodes_q))
			while (node_path(nodes_q)[i])
				ft_printf("%d -> ", node_path(nodes_q)[i++]);
		ft_printf("NULL\n");
		if (!nodes_q->next)
			return ;
		else
		{
			ft_printf("\n");
			nodes_q = nodes_q->next;
		}
	}
}
