/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 11:38:08 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2));
		if (!(new = ft_memalloc(len + 1)))
			return (NULL);
		ft_strcat(new, s1);
		ft_strcat(new, s2);
		return (new);
	}
	return (NULL);
}
