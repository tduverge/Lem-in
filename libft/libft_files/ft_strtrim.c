/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:13 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:29:26 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*s_n;
	char	*blank;

	if (s)
	{
		s_n = (char *)s;
		i = 0;
		j = ft_strlen(s) - 1;
		while (s_n[i] && (s_n[i] == ' ' || s_n[i] == '\t' || s_n[i] == '\n'))
			i++;
		while (s_n[j] && (s_n[j] == ' ' || s_n[j] == '\t' || s_n[j] == '\n'))
			j--;
		if (s_n[i] == '\0')
		{
			blank = ft_strnew(1);
			*blank = '\0';
			return (blank);
		}
		return (ft_strsub(s, i, j - i + 1));
	}
	return (NULL);
}
