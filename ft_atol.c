/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 17:27:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 11:00:56 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

long	ft_atol(const char *str, int *check)
{
	long	nb;
	int		neg;
	int		i;

	nb = 0;
	i = (str[0] == '-' || str[0] == '+' ? 0 : -1);
	while (str[++i])
		if (!ft_isdigit(str[i]))
		{
			*check = 1;
			return (0);
		}
	i = 0;
	neg = (str[i] == '-' ? 1 : 0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (neg ? -nb : nb);
}
