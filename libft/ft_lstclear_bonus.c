/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:40:54 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/19 18:50:47 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstdel;

	while (lst[0] != NULL)
	{
		lstdel = lst[0];
		lst[0] = lst[0]->next;
		ft_lstdelone(lstdel, del);
	}
}
