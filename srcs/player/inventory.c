/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:24:29 by jaberkro          #+#    #+#             */
/*   Updated: 2022/03/08 12:19:31 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cluster.h"
#include "player.h"
#include <assert.h>
#include <string.h>

int	bag_amount_check(t_player *player) {
	int total_amount = player->amount[0] + player->amount[1];
	if (total_amount < 2)
		return (0);
	return (1);
}

void	generate_random_colours(t_player *player, int *col_a, int *col_b) {
	int picked_colour;

	srand(time(0));
	picked_colour = rand() % 2;
	if (player->amount[picked_colour] > 0) {
		*col_a = player->col[picked_colour];
		player->amount[picked_colour] -= 1;
	}
	else {
		*col_a = player->col[(picked_colour + 1) % 2];
		player->amount[(picked_colour + 1) % 2] -= 1;
	}
	
	picked_colour = rand() % 2;
	if (player->amount[picked_colour] > 0) {
		*col_b = player->col[picked_colour];
		player->amount[picked_colour] -= 1;
	}
	else {
		*col_b = player->col[(picked_colour + 1) % 2];
		player->amount[(picked_colour + 1) % 2] -= 1;
	}
}

// int	update_inventory(t_player* player, int colour_index) {
// 	player->amount[colour_index]++;
// 	return (0);
// }

//const t_tile	*play_turn(bool turn, t_players *players)
//{
//	char	command[3000];
//
//	//randomly grab 2 pieces from the player's bag
//
//	// player give input
//	bzero(command, 3000);
//	while ((command[0] != 'A' && command[0] != 'B' && command[0] != 'R' ) || (command[1] - 48 < 0 || command[1] - 48 > 9))
//		scanf("%s", command);
//	//printf("command=%s, turn = %d, colours: %d, %d\n", command, turn, players->p[turn].col1, players->p[turn].col2);
//
//	// work out player input
//	if (command[0] == 'A') {
//		players->p[turn].amount1 -= 1;
//		return
//		return (get_drop_tile(command[1] - 48, players->p[turn].col1));
//	}
//	else if (command[0] == 'B') {
//		players->p[turn].amount2 -= 1;
//		return (get_drop_tile(command[1] - 48, players->p[turn].col2));
//	}
//	else if (command[0] == 'R') {
//		printf("let's rotate!\n");
//		rotate_field(command[1] - 48);
//	}
//	return (NULL);
//}
