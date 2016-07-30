/* Backtracking | Set 2 (Rat in a Maze) backtracking
 * Following is binary matrix representation of the above maze.
 *
 * Following is binary matrix representation of the above maze.

                {1, 0, 0, 0}
                {1, 1, 0, 1}
                {0, 1, 0, 0}
                {1, 1, 1, 1}
 * Following is the solution matrix (output of program) for the above input matrx.

                {1, 0, 0, 0}
                {1, 1, 0, 0}
                {0, 1, 0, 0}
                {0, 1, 1, 1}
 All enteries in solution path are marked as 1.
*/
#include <stdio.h>

int maze1[4][4] ={{1, 0, 0, 0},
                 {1, 1, 1, 1},
                 {0, 1, 0, 1},
                 {1, 0, 0, 1}};

int maze2[4][4] ={{1, 0, 0, 0},
                 {1, 1, 0, 1},
                 {0, 1, 0, 1},
                 {1, 1, 1, 1}};
int path[4][4];

int
find_path(int maze[][4], int path[][4], int x, int y)
{
	if (x==3 && y==3) 
		return 1;
	else {
		if (maze[x+1][y]) {
			path[x+1][y]=1;
			if (!find_path (maze, path, x+1, y)) {
				path[x+1][y]=0;
			} else {
				return 1;
			}
		}
		if (maze[x][y+1]) {
			path[x][y+1]=1;
			if (!find_path (maze, path, x, y+1)) {
				path[x][y+1]=0;
			} else {
				return 1;
			}
		} 
	}
	return 0;
}

void print_arr(int arr[][4]) 
{
	int i=0, j=0;
	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			printf ("%d\t", arr[i][j]);
		}
		printf ("\n");
	}
	return;
}

int main ()
{

	path[0][0]=1;
	printf ("%d\n", find_path (maze2, path, 0, 0));
	print_arr (path);
	return 0;
}
