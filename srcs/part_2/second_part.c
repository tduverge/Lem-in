/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   second_part.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/03 18:35:51 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 18:17:28 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			**ft_second_part(t_room *start, t_list *rooms)
{
	int		i;
	int		max_path;
	int		**paths;

	if (!(max_path = ft_count_max_path(start, rooms)))
		return (0);
	if (!(paths = (int **)ft_memalloc(sizeof(int *) * (max_path + 1))))
		return (NULL);
	i = 0;
	while (i < max_path)
		paths[i++] = ft_get_shortest_path(paths, start, rooms);
	return (paths);
}
