/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_moves.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:55 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:55 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static char		*get_name_by_id(t_list *rooms, int id)
{
	while (id--)
		rooms = rooms->next;
	return (room(rooms).name);
}

static int		forward(int **ants, t_list *rooms,
		int nb_ants, int *ants_per_path)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < nb_ants)
		if (ants[i] && *ants[i])
		{
			ft_printf(j ? " L%d-%s" : "L%d-%s", i + 1,
					get_name_by_id(rooms, *ants[i] - 1));
			ants[i]++;
			j = 1;
		}
	if (ants_per_path[0])
		ft_putchar(' ');
	return (j);
}

static int		calc_nb_path(int **paths)
{
	int		i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}

static void		launch(int **paths, int *ants_per_path,
		int **ants, t_list *rooms)
{
	int		i;
	int		j;
	int		k;
	int		nb_paths;

	nb_paths = calc_nb_path(paths);
	i = -1;
	k = 0;
	while (++i < nb_paths)
		if (ants_per_path[i])
		{
			j = 0;
			while (ants[j])
				j++;
			ants[j] = paths[i];
			ft_printf(k ? " L%d-%s" : "L%d-%s", j + 1,
					get_name_by_id(rooms, *ants[j] - 1));
			k = 1;
			ants[j]++;
			ants_per_path[i]--;
		}
	ft_putchar('\n');
}

int				print_moves(int **paths, int *ants_per_path,
		t_list *rooms, int nb_ants)
{
	int		**ants;
	int		i;

	if (!(ants = (int **)ft_memalloc((nb_ants) * sizeof(int *))))
		return (0);
	i = 1;
	while (i || forward(ants, rooms, nb_ants, ants_per_path))
	{
		launch(paths, ants_per_path, ants, rooms);
		i = 0;
	}
	free(ants);
	return (1);
}
