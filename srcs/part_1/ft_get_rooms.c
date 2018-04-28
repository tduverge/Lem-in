/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_rooms.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:46 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 10:39:02 by tduverge    ###    #+. /#+    ###.fr     */
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
	if (ft_strchr(name, '-'))
		return (1);
	while (rooms)
	{
		if (!ft_strcmp(room(rooms).name, name))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

static int	get_node(t_list **rooms, char *line, int pos)
{
	char	**splits;
	char	*name;
	long	x;
	long	y;

	if (!ft_is_valid_room(line))
		return (0);
	splits = ft_strsplit(line, ' ');
	name = ft_strdup(splits[0]);
	x = ft_strlen(splits[1]) < 12 ? ft_atol(splits[1], 0) : (long)MA + 1;
	y = ft_strlen(splits[2]) < 12 ? ft_atol(splits[2], 0) : (long)MA + 1;
	if (x < MI || x > MA || y < MI || y > MA || ft_is_known(name, *rooms))
		return (ft_free_split(name, splits, 0));
	ft_lstpush(rooms, lstnew_room(name, pos, x, y));
	return (ft_free_split(NULL, splits, 1));
}

int			ft_get_rooms(t_list **rooms, t_room **start, char *line, int step)
{
	start++;
	if (line[0] == 'L')
		return (0);
	if (step == 12)
		return (get_node(rooms, line, S));
	else if (step == 14)
		return (get_node(rooms, line, E));
	else
		return (get_node(rooms, line, X));
}
