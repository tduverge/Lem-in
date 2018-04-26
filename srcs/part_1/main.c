/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:50 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:33:50 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

static int		ex_prg(t_list *rooms, int err, int first, char *stock)
{
	if (err == -1 && !first)
	{
		ft_printf("ERROR\n");
		first = 1;
	}
	if (stock)
		ft_memdel((void**)&stock);
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
	char		*stock;

	(void)argc;
	(void)argv;
	if (!(ft_parsing(&start, &rooms, &stock)))
		return (ex_prg(rooms, -1, 0, stock));
	if (!(paths = ft_second_part(start, rooms)))
		return (ex_prg(rooms, -1, 0, stock));
	paths[0] ? ft_printf("%s\n", stock) : 0;
	paths[0] ? print_sol(paths, start, rooms) : 0;
	free_paths(paths);
	return (paths[0] ? ex_prg(rooms, 0, 0, stock)
			: ex_prg(rooms, -1, 0, stock));
}
