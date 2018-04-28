/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:45 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 10:33:07 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			ft_check_rooms(t_list *rooms)
{
	int		ext;
	t_list	*start;

	ext = 0;
	start = rooms;
	while (rooms)
	{
		if (room(rooms).pos == S)
		{
			if (ext % 10 == 1)
				return (0);
			ext += 1;
		}
		if (room(rooms).pos == E)
		{
			if (ext / 10 == 1)
				return (0);
			ext += 10;
		}
		rooms = rooms->next;
	}
	return (ext == 11 ? 1 : 0);
}

char		**ft_is_valid_link(char *line, t_list *rooms)
{
	int			i;
	int			count;
	char		**splits;

	i = 0;
	count = 0;
	while (line[i])
		count += (line[i++] == '-' ? 1 : 0);
	if (count != 1 || !(splits = ft_strsplit(line, '-')))
		return (0);
	if (!ft_is_known(splits[0], rooms) || !ft_is_known(splits[1], rooms))
	{
		ft_free_split(NULL, splits, 0);
		return (NULL);
	}
	return (splits);
}

int			ft_is_valid_room(char *line)
{
	int		i;
	int		count;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	count = (line[i++] == ' ' ? 1 : 0);
	while (line[i] == ' ')
		i++;
	line[i] == '-' ? i++ : 0;
	while (ft_isdigit(line[i]))
		i++;
	count += (line[i++] == ' ' ? 1 : 0);
	while (line[i] == ' ')
		i++;
	if (count != 2)
		return (0);
	line[i] == '-' ? i++ : 0;
	while (ft_isdigit(line[i]))
		i++;
	return (line[i] ? 0 : 1);
}
