/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:34:16 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 22:53:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static int		ft_ants(char **stock)
{
	char		*line;
	int			i;
	int			ants;

	i = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_stock(stock, line);
		if (line[0] != '#')
			break ;
		ft_memdel((void**)&line);
	}
	if (!line)
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
	{
		ft_memdel((void**)&line);
		return (0);
	}
	ants = ft_atoi(line);
	ft_memdel((void**)&line);
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

int				ft_free_n_return(char *stock, char *links, int ret)
{
	if (stock)
		ft_memdel((void**)&stock);
	if (links)
		ft_memdel((void**)&links);
	return (ret);
}

int				ft_parsing(t_room **start, t_list **rooms, char **stock)
{
	int			ants;
	char		*links;

	*start = NULL;
	*rooms = NULL;
	links = NULL;
	*stock = ft_memalloc(0);
	if (!(ants = ft_ants(stock)))
		return (0);
	if (!(ft_get_rooms(rooms, start, &links, stock)))
		return (ft_free_n_return(NULL, links, 0));
	if (*start)
		(*start)->ants = ants;
	if (!(ft_check_rooms(*rooms, links)))
		return (ft_free_n_return(NULL, links, 0));
	if (!(ft_links(rooms, links, stock)))
		return (ft_free_n_return(NULL, NULL, 0));
	ft_setid(*rooms);
	return (1);
}
