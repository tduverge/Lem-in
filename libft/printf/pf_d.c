/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_d.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 15:15:59 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 09:13:57 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

int			pf_d(va_list ap, t_flags *flags, char **str, int len)
{
	int		ret;
	char	*next;
	char	*tmp;

	flags->type == 'D' ? flags->modif = l : 0;
	if (flags->modif == null)
		next = pf_litoa_base(va_arg(ap, int), "0123456789");
	else if (flags->modif == h)
		next = pf_litoa_base((short)va_arg(ap, int), "0123456789");
	else if (flags->modif == hh)
		next = pf_litoa_base((char)va_arg(ap, int), "0123456789");
	else
		next = pf_litoa_base(va_arg(ap, long), "0123456789");
	if (!next)
		return (-1);
	if (!(pf_applyflags_nb(&next, flags)))
		return (-1);
	ret = ft_strlen(next);
	tmp = *str;
	if (!(*str = ft_strnjoin(*str, next, len)))
		return (-1);
	free(tmp);
	free(next);
	return (ret);
}
