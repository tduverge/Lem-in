/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 16:49:37 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 15:26:48 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

t_room		room(t_list *lst)
{
	return (*(t_room *)lst->content);
}

t_list		*lstnew_room(char *name, int pos, int x, int y)
{
	t_room		*tmp;
	t_list		*new;

	tmp = create_room(name, pos, x, y);
	new = ft_lstnew(tmp, sizeof(t_room));
	free(tmp);
	return (new);
}

t_room		*create_room(char *name, int pos, int x, int y)
{
	t_room		*new_room;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new_room->links = NULL;
	new_room->name = name;
	new_room->ants = 0;
	new_room->x = x;
	new_room->y = y;
	new_room->pos = pos;
	new_room->visited = 0;
	return (new_room);
}

void		del_room(t_list *room)
{
	if (room->next)
		del_room(room->next);
	free_links(((t_room*)room->content)->links);
	free(((t_room*)room->content)->name);
	free(room->content);
	free(room);
}
