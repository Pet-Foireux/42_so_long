/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:57:59 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/20 13:32:35 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int handle_key(int key, t_move *move)
{
    if (key == 'w')
        move->new_y -= 1;
    if (key == 's')
        move->new_y += 1;
    if (key == 'a')
        move->new_x -= 1;
    if (key == 'd')
        move->new_x += 1;
    // if (key == 65307)
    //     handle_exit();
    if (key == 'w' || key == 'a' || key == 's' || key == 'd')
    {
        if (can_move(move))
            update(move);
    }
    return (0);
}

int update(t_move *move)
{
    move->last_x = move->player_x;
    move->last_y = move->player_y;
    move->player_x = move->new_x;
    move->player_y = move->new_y;
    print(move->init, move->init->player_img, move->player_x, move->player_y);
    print(move->init, move->init->floor_img, move->last_x, move->last_y);
    return (0);
}

int can_move(t_move *move)
{
    // printf("%c\n", move->init->map[1][1]);
    if (move->init->map[move->new_y][move->new_x] == '1')
        return (0);
    // if (move->init->map[move->new_y][move->new_x] == 'C')
    // {
    //     move->init->map[move->new_y][move->new_x] = '0';
    //     move->count->count_piece--;
    // }
    // if (move->init->map[move->new_y][move->new_x] == 'E' && move->count->count_piece != 0)
    //     return (0);
    return (1);
}