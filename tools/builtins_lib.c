/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:24:00 by zadriouc          #+#    #+#             */
/*   Updated: 2024/10/21 01:24:11 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int     ft_strlen(const char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr_fd(const char *str, int fd)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}
