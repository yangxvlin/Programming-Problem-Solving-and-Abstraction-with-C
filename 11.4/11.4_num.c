#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_PER_LINE 2
#define MY_FILE "file.dat"

int main(int argc, char *argv[]) {
	FILE *fp;
	double num[2] = {1.001, 2.000};
	int i;
	
	fp = fopen(MY_FILE, "w");
	i = fwrite(num, sizeof(*num), NUM_PER_LINE, fp);
	assert(i == NUM_PER_LINE);
	
	printf("%.5lf\n", num[0]);
	num[0] *= 2.0;
	printf("%.5lf\n", num[0]);
	
	fp = freopen(MY_FILE, "a", fp);
	i = fwrite(num, sizeof(*num), NUM_PER_LINE, fp);
	assert(i == NUM_PER_LINE);
	
	fclose(fp);
	
	
	fp = freopen(MY_FILE, "r", fp);
	i = fread(num, sizeof(*num), NUM_PER_LINE, fp);
	assert(i == NUM_PER_LINE);
	int j;
	for (j = 0; j < i; j++) {
		printf("%.3lf ", num[j]);
	}
	fclose(fp);
}

