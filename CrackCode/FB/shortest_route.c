#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
	int x;
	int y;
	int depth;
} Point;

typedef struct Queue {
	struct Queue *next;
	Point *p;
} Queue;

Point *
newpoint (int x, int y, int depth) 
{
	Point *new = malloc (sizeof(Point));
	new->x = x;
	new->y = y;
	new->depth = depth;

	return new;
}

int 
isSafe (int x, int y, int n) {
	if (x >=0  && x<n && y>=0 && y<n)
		return 1;
	return 0;
}

void Enqueue (Queue **q, Point *data) { return;  }
Point * Dequeue (Queue **q) {return NULL;}
int isEmpty (Queue *q) {return 0;}

int
BFS (int n, int Matrix[][n], int sx, int sy, int dx, int dy)
{
	int i=0, j=0, x=0, y=0;
	Queue *q = NULL;
	Point *p = NULL, *newp = NULL;

	int rows[] = {1, 1, 0, -1,  0, -1, -1,  1};
	int cols[] = {1, 0, 1,  0, -1, -1,  1, -1};

	int Visited[n][n];
	memset (Visited, 0, sizeof (Visited));

	p = newpoint (sx, sy, 0);
	Visited[sx][sy] = 1;
	Enqueue (&q, p);

	while (!isEmpty(q)) {

		p = Dequeue (&q);

		if (p->x == dx && p->y == dy) {
			return p->depth;
		}

		for (i=0; i<8; i++) {
			x = p->x + rows[i];
			y = p->y + cols[i];
			if (isSafe (x, y, n) && !Visited[x][y] && Matrix[x][y] == 0) {
				Visited[x][y] = 1;
				newp = newpoint (x, y, p->depth + 1);
				Enqueue (&q, newp);
			}
		}

		free (p);
	}

	return -1;
}

int main ()
{
	return 0;
}
