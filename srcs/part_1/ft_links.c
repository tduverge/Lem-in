/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_links.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 18:47:53 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 16:38:23 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static t_list	*get_room_byname(t_list *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(room(rooms).name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

static int		ft_attribute_links(t_list *rooms, char *source, char *dest)
{
	t_list		*first;
	t_list		*second;

	first = get_room_byname(rooms, source);
	second = get_room_byname(rooms, dest);
	ft_linkpush(&((t_room *)first->content)->links, (t_room *)second->content);
	ft_linkpush(&((t_room *)second->content)->links, (t_room *)first->content);
	return (1);
}

int				ft_exist_link(t_list *rooms, char *source, char *dest)
{
	t_room		cur_room;

	while (rooms && ft_strcmp(((t_room *)(rooms->content))->name, source)
			&& ft_strcmp(((t_room *)(rooms->content))->name, dest))
		rooms = rooms->next;
	cur_room = room(rooms);
	while (cur_room.links)
	{
		if (!ft_strcmp(((t_room *)(cur_room.links->room))->name, source) ||
				!ft_strcmp(((t_room *)(cur_room.links->room))->name, dest))
			return (0);
		cur_room.links = cur_room.links->next;
	}
	return (1);
}

int				ft_first_link(t_list **rooms, char *links)
{
	char		**splits;

	if (ft_comment_links(links))
	{
		if (!(splits = ft_is_valid_link(links, *rooms)))
			return (ft_free_split(links, splits, 0));
		if (ft_exist_link(*rooms, splits[0], splits[1]))
			ft_attribute_links(*rooms, splits[0], splits[1]);
		ft_free_split(NULL, splits, 0);
	}
	free(links);
	return (1);
}

int				ft_links(t_list **rooms, char *links, char **stock)
{
	char		**splits;
	char		*line;
	int			i;

	i = 0;
	if (!(ft_first_link(rooms, links)))
		return (0);
	while (get_next_line(0, &line, 0) > 0)
	{
		ft_stock(stock, line);
		if (ft_comment_links(line))
		{
			if (!(splits = ft_is_valid_link(line, *rooms)))
				return (ft_free_split(line, splits, 0));
			if (ft_exist_link(*rooms, splits[0], splits[1]))
				ft_attribute_links(*rooms, splits[0], splits[1]);
			ft_free_split(NULL, splits, 0);
		}
		free(line);
	}
	return (1);
}
