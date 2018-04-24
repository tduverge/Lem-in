/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:05 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 11:23:01 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
