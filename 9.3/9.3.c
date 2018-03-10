#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK 52
#define ROUND 10000
#define HAND_CARD 5
#define PLAYER_NUM 4 

typedef struct {
	int face_value;
	char face_string[3];
} face_t;

typedef struct {
	int id;
	face_t face;
	char suit;
} card_t;

typedef struct {
	int hand_card[5];
} player_t;

char SUIT[] = {'H', 'D', 'S', 'C'};

void print_hand(card_t card[], int n);
void deck_ini(card_t card[]);
int hand_check(int card, int hand[], int n);
void give_card(player_t player[], int n, int seed);
void print_player_hand(player_t player[], int n);
int hand_pair_check(int hand[], int n, card_t card[]);
void table(card_t card[], int *p, player_t player[]);
void seed_generater(int a[]);
int hand_kind_check(int hand[], int n, card_t card[]);
int hand_house_check(int hand[], int n, card_t card[]);
void print_one_player_hand(int a[]);

int main() {
	int i, j, p1[3] = {0, 0, 0}, pair = 0;
	card_t card[52];
	int seed[ROUND];
	seed_generater(seed);
	
	deck_ini(card);
	
	//print_hand(card, DECK);
	player_t player[ROUND][4];
	
	
	for (j = 0; j < ROUND; j++) {
		give_card(player[j], 4, seed[j]);
		table(card, p1, player[j]);
	}
	
	printf("one pair: %d\none house: %d\none house and one pair: %d\n", p1[0], p1[1], p1[2]);
}

void seed_generater(int a[]) {
	int i;
	srand(time(0));
	for (i = 0; i < ROUND; i++) {
		a[i] = rand() % ROUND;
	}
}

void table(card_t card[], int p[], player_t player[]) {
	int k, sum = 0;
	
	//print_player_hand(player, 4);
	for (k = 0; k < PLAYER_NUM; k++) {
		//printf("%d\n", k);
		p[0] += hand_pair_check(player[k].hand_card, HAND_CARD, card);
		//printf("%d\n", sum);
		p[1] += hand_kind_check(player[k].hand_card, HAND_CARD, card);
		p[2] += hand_house_check(player[k].hand_card, HAND_CARD, card);
	}
	//printf("%d\n", sum);
	//return sum;
}

int hand_house_check(int hand[], int n, card_t card[]) {
	int i, j, k, house = 0, m, p;
	
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j+1; k < n; k++) {
				if ((card[hand[i]].face.face_value ==
					card[hand[j]].face.face_value) && 
					(card[hand[j]].face.face_value ==
					card[hand[k]].face.face_value)) {
						//printf("%s %s %s\n", card[hand[k]].face.face_string, card[hand[i]].face.face_string, card[hand[j]].face.face_string);
						for (m = 0; m < n; m++) {
							if ((m != i) && (m != j) && (m != k)) {
								for (p = 0; p < n; p++) {
									if ((p != i) && (p != j) && (p != k) && (p != m)) {
										if ((card[hand[m]].face.face_value ==
											card[hand[p]].face.face_value) && 
											(card[hand[m]].suit != card[hand[p]].suit)) {
												house++;
										}
									}
								}
							}
						}
					}
			}
		}
	}
	return house;
}

int hand_kind_check(int hand[], int n, card_t card[]) {
	int i, j, k, pair = 0;
	//print_one_player_hand(hand);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j+1; k < n; k++) {
				if ((card[hand[i]].face.face_value ==
					card[hand[j]].face.face_value) && 
					(card[hand[j]].face.face_value ==
					card[hand[k]].face.face_value)) {
						//printf("%s %s %s\n", card[hand[k]].face.face_string, card[hand[i]].face.face_string, card[hand[j]].face.face_string);
						pair++;
					}
			}
		}
	}
	
	return pair;
}

int hand_pair_check(int hand[], int n, card_t card[]) {
	int i, j, pair = 0;
	
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if ((card[hand[i]].face.face_value ==
				card[hand[j]].face.face_value) && 
				(card[hand[i]].suit != card[hand[j]].suit)) {
					pair++;
			}
		}
	}
	
	return pair;
}

void give_card(player_t player[], int n, int seed) {
	int i, j, card_counter[20], num = 0, card;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n+1; j++) {
			srand(seed);
			
			while (1) {
				card = rand() % 51;
				
				if (hand_check(card, card_counter, num) == 1) {
					player[i].hand_card[j] = card;
					card_counter[num] = card;
					num++;
					break;
				}
			}
		}
	}
}

int hand_check(int card, int hand[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		if (card == hand[i]) {
			return 0;
		}
	}
	
	return 1;
}

void deck_ini(card_t card[]) {
	int i, j = 0, k = 1;

	for (i = 0; i < DECK; i++) {
		card[i].id = i;
		
		card[i].suit = SUIT[j];
		
		card[i].face.face_value = k;
		
		switch (k) {
			case 1:
				card[i].face.face_string[0] = 'A';
				card[i].face.face_string[1] = 'c';
				card[i].face.face_string[2] = '\0';
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				card[i].face.face_string[0] = (char) (k + 48);
				card[i].face.face_string[1] = '\0';
				break;
			case 10:
				card[i].face.face_string[0] = '1';
				card[i].face.face_string[1] = '0';
				card[i].face.face_string[2] = '\0';
				break;
			case 11:
				card[i].face.face_string[0] = 'J';
				card[i].face.face_string[1] = 'a';
				card[i].face.face_string[2] = '\0';
				break;
			case 12:
				card[i].face.face_string[0] = 'Q';
				card[i].face.face_string[1] = 'u';
				card[i].face.face_string[2] = '\0';
				break;
			case 13:
				card[i].face.face_string[0] = 'K';
				card[i].face.face_string[1] = 'i';
				card[i].face.face_string[2] = '\0';
				break;
			default:
				break;
		}
		
		k++;
		if (k > 13) {
			k = 1;
			j++;
		}
	}
}

void print_hand(card_t card[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("#card[%2d], (%2d)%2s-%c\n", card[i].id, card[i].face.face_value, card[i].face.face_string, card[i].suit);
	}
}

void print_player_hand(player_t player[], int n) {
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n+1; j++) {
			printf("%d ", player[i].hand_card[j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_one_player_hand(int a[]) {
	int i;
	for (i = 0; i < HAND_CARD; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

