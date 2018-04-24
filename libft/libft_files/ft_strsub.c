/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:12 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:29:24 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	char	*cur;

	if (s)
	{
		if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		cur = (char *)s + start;
		i = 0;
		while (cur[i] && (i < len))
		{
			sub[i] = cur[i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
