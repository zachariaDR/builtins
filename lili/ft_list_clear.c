/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:17:54 by zadriouc@st       #+#    #+#             */
/*   Updated: 2024/09/25 15:38:06 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_a_list.h"

void ft_list_clear(t_env **begin_list, void (*free_fct)(void *))
{
    t_env   *delter;
    int     size;

	if (!begin_list || !(*begin_list) || !free_fct)
		return ;
    delter = *begin_list;    
    size = 0;
    // while (delter)
    // {
    //     delter = delter->next;
    //     size++;
    // }
    size = ft_list_size(*begin_list);
    printf("size is %d\n", size);
    while (size--)
        ft_list_del_last(begin_list, free_fct);
}
