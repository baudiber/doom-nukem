/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:53 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;
	t_list	*new;

	if (!lst && !f)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (!new)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!new)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
