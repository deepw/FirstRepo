/* 
 * 19.5  The Game of Master Mind is played as follows:
 * The computer has four slots containing balls that are red (R), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).
 * You, the user, are trying to guess the solution. You might, for example, guess YRGB.
 * When you guess the correct color for the correct slot, you get a “hit”. If you guess a color that exists but is in the wrong slot, you get a “pseudo-hit”. For example, the guess YRGB has 2 hits and one pseudo hit.
 * For each guess, you are told the number of hits and pseudo-hits.
 * Write a method that, given a guess and a solution, returns the number of hits and pseudo hits.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int buffer[4];

void
MindGame(char *guess, char *solution, int *hits, int *phits) {
	int i=0,j=0;
	memset(buffer, 0, sizeof(buffer));
	while (guess[i] != '\0') {
		buffer[i] = solution[i];
		if (guess[i] == solution[i]) {
			(*hits)++;
		} else { 
		        for (j=0; j<4; j++) {
				if (guess[i] == buffer[j]) {
					(*phits)++;
				}
			}
		}
		i++;
	}
	return;
}

int
main () {
	char solution[] = "RGGB";
	char guess[5];
        int h=0, p=0;
	printf ("\nguess=?: ");
	gets(guess);
	printf ("%s\n", guess);
	MindGame (guess, solution, &h, &p);
	printf ("\nguess=%s, hits=%d, psuedo-hits=%d\n", guess, h, p);
	return 0;
}

