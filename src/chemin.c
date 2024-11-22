/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:32 by mpapin            #+#    #+#             */
/*   Updated: 2024/11/22 18:28:28 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void flood_fill(t_init *init, int x, int y)
{
    if (x < 0 || x >= init->height || y < 0 || y >= init->widht)
        return ;
    if (init->visited[x][y] == 2)
        return ;

    // Si la case est un mur (valeur 1 dans visited), on ne l'explore pas
    if (init->visited[x][y] == 1)
        return ;

    // Si la case contient une pièce 'C' (par exemple valeur 3 dans visited)
    if (init->visited[x][y] == 3)
        (init->pieces_trouvees)++;

    // Si la case est la sortie 'E' (par exemple valeur 4 dans visited)
    if (init->visited[x][y] == 4)
    {
        init->sortie_trouvee = 1;
        printf("Sortie trouvée à (%d, %d)\n", x, y);
    }
    init->visited[x][y] = 2;
    flood_fill(init, x + 1, y);
    flood_fill(init, x - 1, y);
    flood_fill(init, x, y + 1);
    flood_fill(init, x, y - 1);
}

void check_chemin(t_init *init, t_move *move, t_count *count)
{
    // visited(init);
    init->pieces_trouvees = 0;
    init->sortie_trouvee = 0;
    printf("Player position: x=%d, y=%d\n", move->player_x, move->player_y);
    
    // Affiche les informations sur le nombre de pièces et la sortie
    printf("Initial pieces_trouvees: %d\n", init->pieces_trouvees);
    printf("Initial sortie_trouvee: %d\n", init->sortie_trouvee);
    printf("Nombre de pièces à trouver: %d\n", count->count_piece);
    printf("Player position: x=%d, y=%d\n", move->player_x, move->player_y);
    flood_fill(init, move->player_x, move->player_y);
    cacaprint(init);
    if (init->sortie_trouvee != 1)
    {
        ft_printf("La sortie n'est pas accessible\n");
        ft_exit(init);
    }
    if (init->pieces_trouvees != count->count_piece && init->sortie_trouvee)
    {
        ft_printf("Error\nIl manque des pièces\n");
        ft_exit(init);
    }
}

// void    visited(t_init *init)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i != init->height)
//     {
//         j = 0;
//         while (j != init->widht)
//         {
//             if (init->map[i][j] == '1')
//                 init->visited[i][j] = 1;  // Mur
//             else if (init->map[i][j] == 'C')
//                 init->visited[i][j] = 3;  // Pièce (C)
//             else if (init->map[i][j] == 'E')
//                 init->visited[i][j] = 4;  // Sortie (E)
//             else if (init->map[i][j] == 'P')
//                 init->visited[i][j] = 0;
//             else
//                 init->visited[i][j] = 0;
//             // printf("%d", init->visited[i][j]);
//             printf("%d", init->map[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// }

void    cacaprint(t_init *init)
{
    int i;
    int j;

    i = 0;
    while (i != init->height)
    {
        j = 0;
        while (j != init->widht)
        {
            printf("%d", init->visited[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void map_to_visited(t_init *init)
{
    int i;
    int j;

    init->visited = malloc(sizeof(int *) * (init->height + 1));
    if (!init->visited)
    {
        ft_printf("Error\nPrblm malloc visited\n");
        exit(1);
    }
    i = 0;
    while (i < init->height)
    {
        init->visited[i] = malloc(sizeof(int) * (init->widht + 1));
        if (!init->visited[i])
        {
            ft_printf("Error\nPrblm malloc visited line\n");
            exit(1);
        }
        j = 0;
        while (j < init->widht)
        {
            init->visited[i][j] = init->map[i][j];
            j++;
        }
        init->visited[i][j] = '\0';
        i++;
    }
    init->visited[i] = NULL;
}

