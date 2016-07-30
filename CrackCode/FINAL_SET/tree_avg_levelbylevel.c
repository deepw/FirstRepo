#include <stdio.h>

int 
avg (Treenode *root) 
{
	int sum = 0, size = 0, i = 0, level = 0;
	Treenode *node = NULL;
	if (!root) 
		return -1;

	Queue *q = NULL;
	Enqueue (&q, root);

	while (!isEmpty(q)) {
		size = GetSize (q);
		i=0; sum=0;
		while (i++ < size) {
			node = Dequeue (&q);
			sum += node->data;

			if (node->left) 
				Enqueue (&q, node->left);
			if (node->right)
				Enqueue (&q, node->right);
		}
		printf ("Avg at level %d is %f.\n", level, sum/size);
		level++;
	}

	return 0;
}


