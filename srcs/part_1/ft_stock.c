/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 17:11:46 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 17:11:48 by lotoussa    ###    #+. /#+    ###.fr     */
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
		free (tmp);
		return (0);
	}
	free(tmp);
	tmp = *stock;
	if (!(*stock = ft_strjoin(*stock, "\n")))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
