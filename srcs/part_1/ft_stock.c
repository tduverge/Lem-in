/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 11:33:48 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 09:40:50 by tduverge    ###    #+. /#+    ###.fr     */
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
