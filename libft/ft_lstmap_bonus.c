/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:52:13 by alexfuen          #+#    #+#             */
/*   Updated: 2025/10/17 11:52:16 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*begin;
	void	*next_content;

	if (!lst || !del || !f)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		next_content = f(lst->content);
		node = ft_lstnew(next_content);
		if (!node)
		{
			del(next_content);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, node);
		lst = lst->next;
	}
	return (begin);
}
