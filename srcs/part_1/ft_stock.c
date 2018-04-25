/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 17:11:46 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 15:31:59 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/header.h"

int		ft_stock(char **stock, char *line)
{
	char	*tmp;

	tmp = *stock;
	if (!(*stock = ft_strjoin(*stock, line)))
	{
		ft_memdel((void**)&tmp);
		return (0);
	}
	ft_memdel((void**)&tmp);
	tmp = *stock;
	if (!(*stock = ft_strjoin(*stock, "\n")))
	{
		ft_memdel((void**)&tmp);
		return (0);
	}
	ft_memdel((void**)&tmp);
	return (1);
}
