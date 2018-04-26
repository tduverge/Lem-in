/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:28:58 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:29:08 by tduverge    ###    #+. /#+    ###.fr     */
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
	*lastbuf = *lastbuf ? *lastbuf : ft_memalloc(1);
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

static int		clear_buf(int fd, t_lastbuf **lst, int ret)
{
	t_lastbuf	*tmp;
	t_lastbuf	*before;

	if (ret == 1)
		return (ret);
	before = *lst;
	if (before->fd != fd)
		while (before->next->fd != fd)
			before = before->next;
	tmp = *lst;
	while (tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == *lst)
		*lst = tmp->next;
	else
		before->next = tmp->next;
	ft_memdel((void**)&(tmp->lastbuf));
	ft_memdel((void**)&tmp);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static t_lastbuf	*lst;
	t_lastbuf			*cur;

	if (lst)
	{
		cur = lst;
		while (cur && cur->fd != fd)
			cur = cur->next;
		if (cur)
			return (clear_buf(fd, &lst, fd_next_line(fd, line, &cur->lastbuf)));
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
	return (clear_buf(fd, &lst, fd_next_line(fd, line, &cur->lastbuf)));
}
