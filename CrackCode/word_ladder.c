#include <stdio.h>
#include <stdlib.h>

/* Just putting the basic algorithm here. This uses BFS. Since all words at a certain level are checked in BFS mode, the first time the word is hit, the shortest length is also found there. */

int
word_ladder (start, end, dictionary) {

	while (q not empty) {
		Queue.add {start, 1}
		curr = Queue.pop;

		for words in dictionary {

			if (isAdjacent(word, curr.word)) {
				Queue.add {word, curr.len + 1}


				if (word == end) {
					return curr.len+1;
				}
				dictionary.remove (word);
			}
		}
	}
	return -1;
}
