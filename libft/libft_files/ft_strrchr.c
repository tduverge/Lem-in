/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:12 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:29:18 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	value;
	char	*start;
	char	*end;

	value = (char)c;
	start = (char *)s;
	end = (char *)s;
	while (*end)
		end++;
	if (c == '\0')
		return (end);
	end--;
	while (end >= start)
	{
		if (*end == c)
			return (end);
		end--;
	}
	return (NULL);
}
