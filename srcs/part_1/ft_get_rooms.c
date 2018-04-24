/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_rooms.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 17:39:38 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 16:50:52 by lotoussa    ###    #+. /#+    ###.fr     */
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
			free(splits[i++]);
		free(splits);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
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
	int		x;
	int		y;

	if (pos == E)
	{
		free(line);
		get_next_line(0, &line, 0);
		ft_stock(stock, line);
	}
	if (!ft_is_valid_room(line))
	{
		free(line);
		return (0);
	}
	splits = ft_strsplit(line, ' ');
	name = ft_strdup(splits[0]);
	x = ft_atoi(splits[1]);
	y = ft_atoi(splits[2]);
	if (x < 0 || x > 2147483647 || y < 0 || y > 2147483647
			|| ft_is_known(name, *rooms))
	{
		free(name);
		return (ft_free_split(line, splits, 0));
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

	free(line);
	get_next_line(0, &line, 0);
	if (!(ft_stock(stock, line)))
		return (0);
	if (!ft_is_valid_room(line))
		return (ft_free_n_return(line, NULL, 0));
	splits = ft_strsplit(line, ' ');
	name = ft_strdup(splits[0]);
	x = ft_atoi(splits[1]);
	y = ft_atoi(splits[2]);
	if (x < 0 || x > 2147483647 || y < 0 || y > 2147483647
			|| ft_is_known(name, *rooms))
		return (ft_free_split(line, splits, 0));
	ft_lstpush(rooms, lstnew_room(name, S, x, y));
	*start = (t_room *)(*rooms)->content;
	return (ft_free_split(line, splits, 1));
}

int			ft_get_rooms(t_list **rooms, t_room **start, char **links,
				char **stock)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret && get_next_line(0, &line, 0) > 0)
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
				free(line);
		}
		else
			ret = get_node(rooms, line, X, stock);
	}
	if (line[0] == 'L' || (ret && (*links = ft_strdup(line)) && line && *line))
		free(line);
	return (ret);
}
