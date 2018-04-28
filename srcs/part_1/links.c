/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   links.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:49 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

void		free_links(t_link *links)
{
	if (!links)
		return ;
	if (links->next)
		free_links(links->next);
	ft_memdel((void**)&links);
}

t_link		*ft_create_link(t_room *room)
{
	t_link		*new_link;

	if (!(new_link = ft_memalloc(sizeof(t_link))))
		return (NULL);
	new_link->room = room;
	new_link->next = NULL;
	return (new_link);
}

t_link		*ft_linkpush(t_link **links, t_room *room)
{
	t_link		*link;

	link = *links;
	if (!link)
	{
		if (!(*links = ft_create_link(room)))
			return (NULL);
		return (*links);
	}
	while (link->next)
		link = link->next;
	if (!(link->next = ft_create_link(room)))
		return (NULL);
	return (link->next);
}

int			ft_linkslen(t_link *links)
{
	int		i;

	i = 0;
	while (links)
	{
		links = links->next;
		i++;
	}
	return (i);
}
