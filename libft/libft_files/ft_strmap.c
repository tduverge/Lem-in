/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 18:37:10 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:29:17 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	if (s)
	{
		if (!(new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = f((char)(s[i]));
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
