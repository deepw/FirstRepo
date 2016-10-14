#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    int key, value;
} node;

typedef struct Queue {
    node *Head;
    node *Tail;
    int size;
    int max_size;
} Queue;

typedef struct Hash {
    node **harr;
    int cap;
} Hash;

Queue Q;
Hash H;

void lruCacheInit(int capacity) {
    H.harr = calloc (1000000*sizeof(node*), 1);
    
    Q.max_size = capacity;
    Q.Head = malloc (sizeof(node));
    Q.Tail = Q.Head;
}

void lruCacheFree() {
    node *p = Q.Tail;
    node *save = NULL;
    while (p) {
        save = p->next;
        free (p);
        p = save;
    }
    free (H.harr);
    return;
}

int lruCacheGet(int key) {
    node *p = H.harr[key];
    int rv = -1;
    if (p) {
        rv = p->value;
        
        if (p != Q.Head) {
            /* Move p to the front of the Q */
            p->next->prev = p->prev;
            p->prev->next = p->next;
        
            Q.Head->next = p;
            p->prev = Q.Head;
        
            Q.Head = p;
        }
    }
    return rv;
}
    
void lruCacheSet(int key, int value) {
    node *p = NULL;
    if (Q.size >= Q.max_size) {
        /* Need to remove one of the nodes from the queue */
        p = Q.Tail->next;
        H.harr[p->key] = NULL;

	if (p == Q.Head) {
		Q.Head = Q.Tail;
	} else {
        	Q.Tail->next = p->next;
        	p->next->prev = Q.Tail;
	}

        Q.size--;
        
        free(p);
    }
    
    /* Add this to the Queue and hash */
    p = malloc (sizeof(node));
    p->key = key;
    p->value = value;
    H.harr[key] = p;
    
    Q.Head->next = p;
    p->prev = Q.Head;
    
    Q.Head = p;
    Q.size++;
    
    return;
}

int main () {
	lruCacheInit(5);
	lruCacheSet(2,1);
	lruCacheSet(3,1);
	lruCacheSet(2,1);
	lruCacheSet(2,1);
	lruCacheSet(10,10);
	lruCacheSet(4,1);
	printf ("Got %d.\n", lruCacheGet(10));
	return 0;
}

