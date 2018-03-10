#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_PER_LINE 1

int main(int argc, char *argv[]) {
	FILE *fp;
	
	assert((fp = fopen(argv[1], "r+")) != NULL);
	
	double num;
	num = fread(&num, sizeof(double), NUM_PER_LINE, fp);
	num *= 2.0;
	//fseek(fp, 1, SEEK_CUR);
	fwrite(&num, sizeof(num), NUM_PER_LINE, fp);
	
	fseek(fp, 100000, SEEK_SET);
	fputc('\n', fp);
	
	fclose(fp);
}

