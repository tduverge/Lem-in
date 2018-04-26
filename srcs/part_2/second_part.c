/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   second_part.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:54 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:54 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			*ft_search_endroom(t_node *nodes_q)
{
	while (nodes_q)
	{
		if (nodes_q->room->pos == E)
			return (nodes_q->path);
		nodes_q = nodes_q->next;
	}
	return (NULL);
}

int			**ft_second_part(t_room *start, t_list *rooms)
{
	int		i;
	int		max_path;
	int		**paths;

	if (!(max_path = ft_count_max_path(start, rooms)))
		return (0);
	if (!(paths = (int **)ft_memalloc(sizeof(int *) * (max_path + 1))))
		return (NULL);
	i = 0;
	while (i < max_path)
		paths[i++] = ft_get_shortest_path(paths, start, rooms);
	return (paths);
}
