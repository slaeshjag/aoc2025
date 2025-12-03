#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int _substrings[13][6] = {
	[0] = { 0 },
	[1] = { 0 },
	[2] = { 1, 0 },
	[3] = { 0 },
	[4] = { 2, 0 },
	[5] = { 0 },
	[6] = { 3, 0 },
	[7] = { 0 },
	[8] = { 4, 0 },
	[9] = { 0 },
	[10] = { 5, 0 },
	[11] = { 0 },
	[12] = { 6, 0 },
};

static int _substrings2[13][6] = {
	[0] = { 0 },
	[1] = { 0 },
	[2] = { 1, 0 },
	[3] = { 1, 0 },
	[4] = { 2, 1, 0 },
	[5] = { 1, 0 },
	[6] = { 3, 2, 1, 0 },
	[7] = { 1, 0 },
	[8] = { 4, 2, 1, 0 },
	[9] = { 3, 1, 0 },
	[10] = { 5, 2, 1, 0 },
	[11] = { 1, 0 },
	[12] = { 6, 4, 3, 2, 1, 0 },
};

static unsigned long long _acc;
static unsigned long long _acc2;

static unsigned long long int _test_number(unsigned long long int num) {
	char buff[12];
	int len;
	int i, j, cnt;


	sprintf(buff, "%llu", num);
	len = strlen(buff);
	
	for (i = 0; _substrings[len][i]; i++) {
		cnt = len / _substrings[len][i];
		for (j = 1; j < cnt; j++) {
			if (strncmp(buff + j*_substrings[len][i], buff, _substrings[len][i]))
				goto next;
		}
		
		return num;
	next:;
	}

	return 0;
}


static unsigned long long int _test_number2(unsigned long long int num) {
	char buff[12];
	int len;
	int i, j, cnt;


	sprintf(buff, "%llu", num);
	len = strlen(buff);
	
	for (i = 0; _substrings2[len][i]; i++) {
		cnt = len / _substrings2[len][i];
		for (j = 1; j < cnt; j++) {
			if (strncmp(buff + j*_substrings2[len][i], buff, _substrings2[len][i]))
				goto next;
		}
		
		return num;
	next:;
	}

	return 0;
}


int main(int argc, char **argv) {
	char buff[2048];
	char *save1, *save2, *rangelow, *rangehigh, *tok;
	unsigned long long int r1, r2, q;

	fgets(buff, 2048, stdin);
	
	for (tok = strtok_r(buff, ",\n", &save1); tok; tok = strtok_r(NULL, ",\n", &save1)) {
		rangelow = strtok_r(tok, "-", &save2);
		rangehigh = strtok_r(NULL, "", &save2);
		r1 = atoll(rangelow);
		r2 = atoll(rangehigh);
		for (q = r1; q <= r2; q++) {
			_acc += _test_number(q);
			_acc2 += _test_number2(q);
		}
	}

	printf("day02a: %llu\n", _acc);
	printf("day02b: %llu\n", _acc2);
	return 0;
}
