/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pow.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:06 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 19:28:17 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_pow(int n, int pow)
{
	long	result;
	size_t	i;

	i = 0;
	if (pow == 0)
		return (1);
	result = n;
	while ((int)i < pow - 1)
	{
		result *= n;
		i++;
	}
	return ((int)result);
}
