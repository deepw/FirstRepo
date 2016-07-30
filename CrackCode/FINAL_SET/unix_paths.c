#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
simplify_path (char *path, char *result) {
	int i = 0, j = 0, l = 0;
	char *dir = NULL;
	char *save = NULL;

	if (!path) return -1;
	dir = strtok_r (path, "/", &save);
	while (dir) {
		if (!strcmp (".", dir)) {
			/* do nothing */
		} else if (!strcmp ("..", dir)) {
			/* move j back */
			j--;
			while (result[j] != '/')
				j--;
		} else {
			result[j++] = '/';
			l = strlen(dir);
			//printf ("dir=%s %d.\n", dir, l);
			memcpy (result+j, dir, l);
			j += l;
		}
		dir = strtok_r (NULL, "/", &save);
	}
	if (j==0) {
		result[j] = '/'; j++;
	}
	result[j] = '\0';
	return 0;
}

int 
simplify_path2 (char *path) {
	int i = 0, j = 0, l = 0;
	char *dir = NULL;
	char *save = NULL;

	if (!path) return -1;
	dir = strtok_r (path, "/", &save);
	while (dir) {
		if (!strcmp (".", dir)) {
			/* do nothing */
		} else if (!strcmp ("..", dir)) {
			/* move j back */
			j--;
			while (path[j] != '/')
				j--;
		} else {
			path[j++] = '/';
			l = strlen(dir);
			//printf ("dir=%s %d.\n", dir, l);
			memcpy (path+j, dir, l);
			j += l;
		}
		dir = strtok_r (NULL, "/", &save);
	}
	if (j==0) {
		path[j] = '/'; j++;
	}
	path[j] = '\0';
	return 0;
}

int 
main ()	{
	char path[] = "/a/b/.././d/../..";
	char result[100];
	printf ("path = %s\n", path);
	//simplify_path (path, result);
	simplify_path2 (path);
	printf ("path = %s\n", path);
	return 0;
}
