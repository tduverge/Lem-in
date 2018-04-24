/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:04 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 10:18:10 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	value;

	i = 0;
	value = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char *)s == value)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
