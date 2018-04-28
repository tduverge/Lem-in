/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:47 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 11:32:07 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static int		ft_ants(char *line)
{
	int			i;
	int			ants;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	ants = ft_atoi(line);
	return (ants > 0 ? ants : 0);
}

void			ft_setid(t_list *rooms)
{
	int		i;

	i = 1;
	while (rooms)
	{
		((t_room *)rooms->content)->id = i;
		rooms = rooms->next;
		i++;
	}
}

int				ft_step(int step, char *line)
{
	if (step == 0)
		return (0);
	else if (step == 20)
		return (20);
	else if (!ft_strcmp(line, "##start") && step != 11 && step != 13)
		return (11);
	else if (!ft_strcmp(line, "##start"))
		return (-1);
	else if (!ft_strcmp(line, "##end") && step != 11 && step != 13)
		return (13);
	else if (!ft_strcmp(line, "##end"))
		return (-1);
	else if (!ft_strchr(line, ' '))
		return (20);
	else if (step == 11 || step == 13)
		return (step + 1);
	return (10);
}

int				ft_end_parsing(t_list **rooms, t_room **start, int ants)
{
	t_list		*tmp;

	if (!(ft_check_rooms(*rooms)))
		return (0);
	tmp = *rooms;
	while (tmp)
	{
		if (((t_room*)(tmp->content))->pos == S)
		{
			*start = (t_room*)(tmp->content);
			break ;
		}
		tmp = tmp->next;
	}
	if (*start)
		(*start)->ants = ants;
	ft_setid(*rooms);
	return (1);
}

int				ft_parsing(t_room **start, t_list **rooms, char **stock)
{
	int			ants;
	char		*line;
	int			step;

	step = 0;
	while (step != -1 && get_next_line(0, &line) > 0)
	{
		ft_stock(stock, line);
		if (*line != '#' ||
				!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			step = ft_step(step, line);
			if (step == 0 && ++step)
				if (!(ants = ft_ants(line)))
					return (ft_free_n_return(line, NULL, 0));
			if (step / 10 == 1 && step % 2 == 0)
				if (!(ft_get_rooms(rooms, start, line, step)))
					return (ft_free_n_return(line, NULL, 0));
			if (step / 10 == 2)
				if (!(ft_links(rooms, line)))
					step = -1;
		}
		ft_memdel((void**)&line);
	}
	return (ft_end_parsing(rooms, start, ants));
}
