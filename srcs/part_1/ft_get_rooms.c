/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_rooms.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 17:39:38 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 18:38:23 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			ft_free_split(char *line, char **splits, int ret)
{
	int		i;

	i = 0;
	if (splits)
	{
		while (splits[i])
			ft_memdel((void**)&(splits[i++]));
		ft_memdel((void**)&splits);
	}
	if (line)
		ft_memdel((void**)&line);
	return (ret);
}

int			ft_is_known(char *name, t_list *rooms)
{
	while (rooms)
	{
		if (!ft_strcmp(room(rooms).name, name))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

static int	get_node(t_list **rooms, char *line, int pos, char **stock)
{
	char	**splits;
	char	*name;
	long		x;
	long		y;

	if (pos == E)
	{
		ft_memdel((void**)&line);
		get_next_line(0, &line, 0);
		ft_stock(stock, line);
	}
	if (!ft_is_valid_room(line))
		return (0);
	splits = ft_strsplit(line, ' ');
	name = ft_strdup(splits[0]);
	x = ft_atol(splits[1]);
	y = ft_atol(splits[2]);
	if (x < MI || x > MA || y < MI || y > MA || ft_is_known(name, *rooms))
	{
		ft_memdel((void**)&name);
		return (ft_free_split(NULL, splits, 0));
	}
	ft_lstpush(rooms, lstnew_room(name, pos == X ? X : E, x, y));
	return (ft_free_split(line, splits, 1));
}

static int	get_start(t_list **rooms, char *line, t_room **start, char **stock)
{
	char	**splits;
	char	*name;
	int		x;
	int		y;

	ft_memdel((void**)&line);
	get_next_line(0, &line, 0);
	if (!(ft_stock(stock, line)))
		return (0);
	if (!ft_is_valid_room(line))
		return (0);
	splits = ft_strsplit(line, ' ');
	name = ft_strdup(splits[0]);
	x = ft_atoi(splits[1]);
	y = ft_atoi(splits[2]);
	if (x < MI || x > MA || y < MI || y > MA || ft_is_known(name, *rooms))
		return (ft_free_split(NULL, splits, 0));
	ft_lstpush(rooms, lstnew_room(name, S, x, y));
	*start = (t_room *)(*rooms)->content;
	return (ft_free_split(line, splits, 1));
}

int			ft_get_rooms(t_list **rooms, t_room **start, char **links,
				char **stock)
{
	char	*line;
	int		ret;
	int		get;

	ret = 1;
	while (ret && (get = get_next_line(0, &line, 0)) > 0)
	{
		if (!(ft_stock(stock, line)))
			return (0);
		ret = (line[0] == 'L' ? 0 : 1);
		if (line[0] == 'L' || ft_strchr(line, '-'))
			break ;
		if (*line == '#')
		{
			if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
				ret = !ft_strcmp(line, "##start") ? get_start(rooms, line,
						start, stock) : get_node(rooms, line, E, stock);
			else
				ft_memdel((void**)&line);
		}
		else
			ret = get_node(rooms, line, X, stock);
	}
	return (ft_norm(links, line, ret, get));
}
