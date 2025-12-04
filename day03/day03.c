#include <stdio.h>
#include <string.h>


long long int _find_biggest_jolt(char *buff, int level) {
	int len, i, j, maxd;
	long long int q, max = 0, n, nt;

	if (!level)
		return 0;
	
	n = 1;
	for (j = 1; j < level; j++)
		n *= 10;
	nt = n;

	len = strlen(buff);
	maxd = 0;
	for (i = len - level; i >= 0; i--) {
		if (buff[i] - '0' < maxd)
			continue;
		maxd = buff[i] - '0';
		q = _find_biggest_jolt(buff + i + 1, level - 1);
		n = nt;
		n *= (buff[i] - '0');
		n += q;
		if (n > max)
			max = n;
	}

	return max;
}



int main(int argc, char **argv) {
	char buff[256];
	int score[256];
	int acc = 0, i, j, len, max, k;
	long long int acc2 = 0, q;

	for (k = 0; fscanf(stdin, "%s\n", buff) == 1; k++) {
		len = strlen(buff);
		for (i = 0; i < len - 1; i++) {
			score[i] = 0;
			for (j = i + 1; j < len; j++) {
				max = (buff[i] - '0') * 10 + (buff[j] - '0');
				if (max > score[i])
					score[i] = max;
			}
		}

		max = 0;
		for (i = 0; i < len - 1; i++)
			if (score[i] > max)
				max = score[i];
		q = _find_biggest_jolt(buff, 12);
		acc2 += q;
		acc += max;
	}
	
	printf("\n");
	printf("day03a: %i\n", acc);
	printf("day03a: %lli\n", acc2);

	return 0;
}
