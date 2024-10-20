/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:13:41 by zadriouc          #+#    #+#             */
/*   Updated: 2024/09/25 15:07:41 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_a_list.h"

void	ft_list_clear_bonus(t_env **lst, void (*del)(void *))
{
	t_env	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		ft_list_del_first(lst, del);
		*lst = tmp;
	}
	ft_list_del_first(lst, del);
	*lst = NULL;
}
