/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_sol.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:34:07 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:34:40 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int			len_path(int *paths)
{
	int		len;

	len = 0;
	while (paths[len])
		len++;
	return (len - 1);
}

int			sum_len_path(int **paths, int nb_paths)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < nb_paths)
		ret += len_path(paths[i++]);
	return (ret);
}

int			*distrib_ants(int **paths, int nb_ants)
{
	int		*ants_per_path;
	int		nb_paths;
	int		i;

	nb_paths = 0;
	while (paths[nb_paths])
		nb_paths++;
	if (!(ants_per_path = ft_memalloc((nb_paths + 1) * sizeof(int))))
		return (NULL);
	while (nb_ants)
	{
		i = 0;
		while (nb_ants < sum_len_path(paths, nb_paths) && nb_paths > 1)
			nb_paths--;
		while (i < nb_paths)
			ants_per_path[i++]++;
		nb_ants -= nb_paths;
	}
	return (ants_per_path);
}

int			print_sol(int **paths, t_room *start, t_list *rooms)
{
	int		*ants_per_path;
	int		i;

	if (!(ants_per_path = distrib_ants(paths, start->ants)))
		return (0);
	i = 0;
	if (!(print_moves(paths, ants_per_path, rooms, start->ants)))
		return (0);
	free(ants_per_path);
	return (1);
}
