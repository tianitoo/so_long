/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:24:45 by hnait             #+#    #+#             */
/*   Updated: 2022/10/23 18:08:57 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	if (!lst || !(*del))
		return ;
	while (*lst)
	{
		tmp_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_lst;
	}
}
