/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:31:31 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:38:49 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static int		ex_prg(t_list *rooms, int err, int first)
{
	get_next_line(0, NULL, 1);
	if (err == -1 && !first)
	{
		ft_printf("ERROR\n");
		first = 1;
	}
	if (!rooms)
		return (err);
	if (rooms)
		del_room(rooms);
	return (err);
}

static void		free_paths(int **paths)
{
	int		i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	if (paths[i])
		free(paths[i]);
	free(paths);
}

int				main(int argc, char **argv)
{
	t_room		*start;
	t_list		*rooms;
	int			**paths;

	(void)argc;
	(void)argv;
	if (!(ft_parsing(&start, &rooms)))
		return (ex_prg(rooms, -1, 0));
	if (!(paths = ft_second_part(start, rooms)))
		return (ex_prg(rooms, -1, 0));
	paths[0] ? print_sol(paths, start, rooms) : 0;
	free_paths(paths);
	return (paths[0] ? ex_prg(rooms, 0, 0) : ex_prg(rooms, -1, 0));
}
