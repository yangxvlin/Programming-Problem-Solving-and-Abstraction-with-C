#include <stdio.h>
#include <stdlib.h>

#define STOP_AT 20
#define START_AT 5
#define TURN 100000
#define BIG_WIN 6
#define ONE_WIN 2
#define BIG_WIN_DICE 12
#define ONE_WIN_DICE 8
#define LOSER_CASH 0
#define WINER_CASH 20
#define SEED 1234567
int main() {
	int cash = START_AT, games_turn = 0, dice1, dice2;
	int	simulation_turn = TURN, winer = 0, loser = 0, win_turn = 0;
	int lose_turn = 0, player_turn = 0;
	
	printf("seed for this run = %d\n", SEED);;
	srand(SEED);
	
	while (simulation_turn > 0) {
		cash = START_AT;
		player_turn = 0;
		while ((cash > LOSER_CASH) && (cash < WINER_CASH)) {
			dice1 = 1 + rand() % 6;
			dice2 = 1 + rand() % 6;
			cash--;
			player_turn++;
			
			if (dice1 + dice2 == BIG_WIN_DICE) {
				cash += BIG_WIN;
			}
			else if (dice1 + dice2 >= ONE_WIN_DICE) {
				cash += ONE_WIN;
			}
		}
		
		if (cash == LOSER_CASH) {
			loser++;
			lose_turn += player_turn;
		}
		else if (cash >= WINER_CASH) {
			winer++;
			win_turn += player_turn;
		}
		
		simulation_turn--;
	}
	
	printf("winning players: %6d, average length %3.1lf games\n", winer, (double) win_turn / (double) winer);
	printf("losing players : %6d, average length %3.1lf games\n", loser, (double) lose_turn / (double) loser);
	printf("overall        : %6d, average length %3.1lf games\n", TURN, ((double) win_turn + (double) lose_turn) / (TURN));
	}

