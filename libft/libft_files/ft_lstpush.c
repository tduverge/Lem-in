/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 10:02:09 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/09 11:40:03 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list		*cur;

	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
