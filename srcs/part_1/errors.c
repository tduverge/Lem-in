/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 18:50:40 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 16:22:02 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			ft_check_rooms(t_list *rooms, char *links)
{
	int		ext;
	t_list	*tmp;
	t_list	*start;

	ext = 0;
	start = rooms;
	while (rooms && (tmp = start))
	{
		if (ft_strchr(room(rooms).name, '-'))
		{
			free(links);
			return (0);
		}
		ext += (room(rooms).pos == 0 || room(rooms).pos == 1 ? 1 : 0);
		rooms = rooms->next;
	}
	return (ext == 2 ? 1 : 0);
}

int			ft_comment_links(char *line)
{
	return (line && line[0] == '#' ? 0 : 1);
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
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	count = (line[i++] == ' ' ? 1 : 0);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	count += (line[i++] == ' ' ? 1 : 0);
	while (line[i] == ' ')
		i++;
	if (count != 2)
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	return (line[i] ? 0 : 1);
}
