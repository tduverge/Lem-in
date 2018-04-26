/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_shortest_path.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:52 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:52 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

void			set_visited(int **paths, t_list *rooms, t_room *start)
{
	int			i;
	int			j;
	t_room		*cur_room;

	while (rooms)
	{
		cur_room = (t_room *)rooms->content;
		cur_room->visited = 0;
		i = 0;
		while (paths[i])
		{
			j = 0;
			while (paths[i][j] && paths[i][j] != cur_room->id)
				j++;
			if (paths[i][j] && cur_room->pos != E)
				cur_room->visited = 1;
			i++;
		}
		rooms = rooms->next;
	}
	start->visited = 1;
}

int				*path_cpy(int *path)
{
	int			*new_path;
	int			i;

	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
		i++;
	new_path = ft_memalloc((i + 1) * sizeof(int));
	i = 0;
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	return (new_path);
}

int				*path_add(int *path, int id)
{
	int			*new_path;
	int			i;

	if (!path)
	{
		new_path = ft_memalloc(2 * sizeof(int));
		*new_path = id;
		return (new_path);
	}
	i = 0;
	while (path[i])
		i++;
	new_path = ft_memalloc((i + 2) * sizeof(int));
	i = 0;
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = id;
	return (new_path);
}

int				add_node(t_node *node)
{
	t_node		*last_node;
	t_link		*link;
	int			new_id;
	t_room		*new_room;

	last_node = node;
	while (last_node->next)
		last_node = last_node->next;
	link = node->room->links;
	while (link)
	{
		new_room = link->room;
		if (new_room->visited == 0)
		{
			new_room->visited = 1;
			new_id = new_room->id;
			last_node->next =
				new_node(path_add(node->path, new_id), new_room, NULL);
			last_node = last_node->next;
		}
		link = link->next;
	}
	return (1);
}

int				*ft_get_shortest_path(int **paths, t_room *start, t_list *rooms)
{
	t_node		*nodes_q;
	int			*end;
	t_node		*tmp;
	int			*end_path;

	set_visited(paths, rooms, start);
	nodes_q = new_node(NULL, start, NULL);
	while (!(end = ft_search_endroom(nodes_q)) && nodes_q)
	{
		add_node(nodes_q);
		tmp = nodes_q;
		nodes_q = nodes_q->next;
		free_node(tmp);
	}
	end_path = path_cpy(end);
	ft_del_node(nodes_q);
	return (end_path);
}
