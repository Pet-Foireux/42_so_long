/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:32 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/22 13:56:26 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    check_chemin(t_init *init )
{
    visited(&init);
    int i;
    int j;
    
}

void    visited(t_init *init)
{
    int i;
    int j;

    i = 0;
    while (i != init->height)
    {
        j = 0;
        while (j != init->widht)
        {
            if (init->map[i][j] == '1')
                init->visited[i][j] = 2;
            if (init->map[i][j] == 'C')
                init->visited[i][j] = 3;
            if (init->map[i][j] == 'P')
                init->visited[i][j] = 4;
            if (init->map[i][j] == 'E')
                init->visited[i][j] = 5;
            if (init->map[i][j] == '0')
                init->visited[i][j] = 0;
            j++;
        }
        i++;
    }
}

