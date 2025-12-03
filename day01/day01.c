#include <stdio.h>


int main(int argc, char **argv) {
	int pos = 50, pos2, step, code = 0, code2 = 0;
	char c, q;

	for (; (q = fscanf(stdin, "%c%i\n", &c, &step)) == 2;) {
		if (c == 'L') {
			pos2 = pos;
			code2 += (step / 100);
			step %= 100;
			pos -= step;
			if (pos < 0) {
				pos = pos + 100;
				if (pos2)
					code2++;
			}
		} else if (c == 'R') {
			code2 += (step / 100);
			step %= 100;
			pos += step;
			if (pos > 100)
				code2++;
			pos %= 100;
		}

		
		if (!pos) {
			code++;
			if (step)
				code2++;
		}
		
	}

	printf("day01a: %i\n", code);
	printf("day01b: %i\n", code2);
	return 0;
}
