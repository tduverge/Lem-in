/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 11:43:59 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:12:21 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

static int		no_read(char **line, char **lastbuf, char *next)
{
	char	*tmp;

	if (!(*line = ft_strsub(*lastbuf, 0, next - *lastbuf)))
		return (-1);
	tmp = *lastbuf;
	if (!(*lastbuf = ft_strdup(next + 1)))
		return (-1);
	free(tmp);
	return (1);
}

static int		fd_next_line(int fd, char **line, char **lastbuf)
{
	char	*next;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	if ((next = ft_strchr(*lastbuf, '\n')))
		return (no_read(line, lastbuf, next));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = *lastbuf;
		if (!(*lastbuf = ft_strjoin(*lastbuf, buf)))
			return (-1);
		free(tmp);
		if ((next = ft_strchr(*lastbuf, '\n')))
			return (no_read(line, lastbuf, next));
		*line = *lastbuf;
		i = 1;
	}
	if (ret == -1)
		return (-1);
	return (i ? i : ret);
}

static int		clear_get(t_lastbuf *lst)
{
	if (lst->next)
		clear_get(lst->next);
	free(lst->lastbuf);
	free(lst);
	return (1);
}

int				get_next_line(int fd, char **line, int clear)
{
	static t_lastbuf	*lst;
	t_lastbuf			*cur;

	if (clear)
		return (clear_get(lst));
	if (lst)
	{
		cur = lst;
		while (cur && cur->fd != fd)
			cur = cur->next;
		if (cur)
			return (fd_next_line(fd, line, &cur->lastbuf));
	}
	if (!(cur = (t_lastbuf *)malloc(sizeof(t_lastbuf))))
		return (-1);
	cur->fd = fd;
	if (lst)
		cur->next = lst;
	else
		cur->next = NULL;
	lst = cur;
	if (!(cur->lastbuf = (char *)ft_memalloc(sizeof(char))))
		return (-1);
	return (fd_next_line(fd, line, &cur->lastbuf));
}
