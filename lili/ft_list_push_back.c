/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:41:26 by zadriouc@st       #+#    #+#             */
/*   Updated: 2024/10/20 13:12:15 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_a_list.h"


void    ft_list_push_back(t_env **begin_list, char *name, char *value)
{
    t_env *n_new;
    t_env *last;

    if (!begin_list || !name || !value)
        return ;
    n_new = ft_create_elem(name, value);
    last = ft_list_last(*begin_list);
    if (!(*begin_list))
        *begin_list = n_new;
    else
        last->next =  n_new;
}
