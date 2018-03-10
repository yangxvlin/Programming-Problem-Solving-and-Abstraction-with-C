#include <stdio.h>

#define MAX_CAR 30
#define MAX_LAP 100
#define MAX_NOTES 40
#define MAX_DRIVER_NAME 50

typedef struct {
	double lap_time[MAX_LAP];
	char notes[MAX_NOTES + 1];
	char driver_name[MAX_DRIVER_NAME + 1];
	int laps_completed;
	double total_time;
	int rank;
} car_t;

int main() {
	car_t race[MAX_CAR];
	int i, j;
	
	race[0].lap_time[0] = 999.999;
	char *notes1 = "abcdefghijklmnopqrstuvwxyz";
	int counter = 0;
	while ((*notes1 != '\0') && (counter < MAX_NOTES)) {
		race[0].notes[counter] = *notes1;
		counter++;
		notes1++;
	}
	race[0].notes[counter] = '\0';
	char *name1 = "ZXCVBNM";
	counter = 0;
	while ((*name1 != '\0') && (counter < MAX_DRIVER_NAME)) {
		race[0].driver_name[counter] = *name1;
		counter++;
		name1++;
	}
	race[0].driver_name[counter] = '\0';
	race[0].laps_completed = 1;
	race[0].total_time = 999.999;
	race[0].rank = -1;
	
	race[1].lap_time[0] = 800;
	race[1].lap_time[1] = 600;
	char *notes2 = "pit stop for fuel and tires";
	counter = 0;
	while ((*notes2 != '\0') && (counter < MAX_NOTES)) {
		race[1].notes[counter] = *notes2;
		counter++;
		notes2++;
	}
	race[1].notes[counter] = '\0';
	char *name2 = "Xulin Yang";
	counter = 0;
	while ((*name2 != '\0') && (counter < MAX_DRIVER_NAME)) {
		race[1].driver_name[counter] = *name2;
		counter++;
		name2++;
	}
	race[1].driver_name[counter] = '\0';
	race[1].laps_completed = 2;
	race[1].total_time = 1400;
	race[1].rank = 1;
	
	for (i = 0; i < 2; i++) {
		printf("The driver is %s ranks %d\n", race[i].driver_name, race[i].rank);
		printf("notes: %s\n", race[i].notes);
		printf("laps completed: %d with total time: %lf seconds\n", race[i].laps_completed, race[i].total_time);
		for (j = 0; j < race[i].laps_completed; j++) {
			printf("  #%d lap with %lf seconds\n", j, race[i].lap_time[j]);
		}
		printf("\n");
	}
}