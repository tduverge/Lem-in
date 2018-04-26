/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count_max_path.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:51 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:51 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static int	is_start_and_end_connect(t_room *start)
{
	t_link		*tmp;

	tmp = start->links;
	while (tmp)
	{
		if (tmp->room->pos == E)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_count_max_path(t_room *start, t_list *rooms)
{
	int		start_path;
	int		end_path;

	if (is_start_and_end_connect(start))
		return (start->ants);
	start_path = ft_linkslen(start->links);
	while (room(rooms).pos != E)
		rooms = rooms->next;
	end_path = ft_linkslen(room(rooms).links);
	return (end_path < start_path ? end_path : start_path);
}
