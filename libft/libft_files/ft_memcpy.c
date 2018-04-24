/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:05 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/03 15:26:00 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*n_dst;
	char	*n_src;

	n_dst = (char *)dst;
	n_src = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		n_dst[i] = n_src[i];
		i++;
	}
	return (dst);
}
