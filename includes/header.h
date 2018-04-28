/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:26:50 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 17:14:36 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/header/libft.h"

# define S 0
# define E 1
# define X 2
# define MI -2147483648
# define MA 2147483647

typedef struct			s_link
{
	struct s_room		*room;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	t_link				*links;
	char				*name;
	int					id;
	int					ants;
	int					x;
	int					y;
	int					pos;
	char				visited;
}						t_room;

typedef struct			s_node
{
	int					*path;
	t_room				*room;
	struct s_node		*next;
}						t_node;

/*
 ** part_1 functions
*/

int						ft_norm(char **links, char *line, int ret, int get);
int						ft_parsing(t_room **start, t_list **rooms, char **stoc);
int						ft_get_rooms(t_list **rooms, t_room **start,
		char *line, int setp);
int						ft_links(t_list **rooms, char *line);
int						ft_is_valid_room(char *line);
char					**ft_is_valid_link(char *line, t_list *rooms);
int						ft_is_known(char *name, t_list *rooms);
int						ft_free_split(char *line, char **splits, int ret);
int						ft_check_rooms(t_list *rooms);
int						ft_stock(char **stock, char *line);
int						ft_free_n_return(char *stock, char *links, int ret);

/*
 ** part_2 functions
*/

int						*ft_search_endroom(t_node *nodes_q);
int						**ft_second_part(t_room *start, t_list *rooms);
int						ft_count_max_path(t_room *start, t_list *rooms);
int						*ft_get_shortest_path(int **paths, t_room *start,
		t_list *rooms);

/*
 ** part_3 functions
*/

int						print_sol(int **paths, t_room *start, t_list *rooms);
int						print_moves(int **paths,
		int *ants_per_path, t_list *rooms, int nb_ants);

/*
 ** Room functions
*/
t_room					room(t_list *lst);
t_room					*create_room();
t_list					*lstnew_room(char *name, int pos, int x, int y);
void					del_room(t_list *room);

/*
 ** Links functions
*/
t_link					*ft_create_link(t_room *room);
t_link					*ft_linkpush(t_link **links, t_room *room);
int						ft_linkslen(t_link *links);
void					free_links(t_link *links);

/*
 ** Node functions
*/
t_room					node_room(t_list *lst);
int						*node_path(t_list *lst);
t_node					*new_node(int *path, t_room *room, t_node *next);
void					ft_del_node(t_node *nodes_q);
void					free_node(t_node *nodes_q);

#endif
