

int read4k (char *buffer);

typedef struct Handle {
	char *buf;
	int pos;
	int sz;
} handle;

int
init_handle (handle **h, int fd) {
	handle *tmp = NULL;
	int sz = 0;
	tmp = malloc (sizeof (handle));
	tmp->buf = malloc(4*1024);
	tmp->pos = 0;
	tmp->sz = 0;
	tmp->fd = fd;
	*h = tmp;
	return 0;
}


int readx (handle *h, char *rbuffer, int x) {
	if (x <= 0)
		return x;

	while (x > 0) {
		if (h->sz == 0 || h->pos == h->sz) {
			h->sz = read4k (h->nbuf, h->fd);
			h->pos = 0;
		}
		/* Read from the internal buffer */
                if (x <= h->sz - h->pos) {
                        memcpy (rbuffer, h->buf + h->pos, x);
                        h->pos += x;
			x = 0;
                } else {
                        memcpy (rbuffer, h->buf+pos, h->sz - h->pos);
                        rbuffer += (h->sz - h->pos);
                        x = x - (h->sz - h->pos);

			bytes = read4k (h->nbuf, fd);
			if (bytes < 0) {
				return bytes;
			} else {
                        	h->pos = 0;
				h->sz = bytes;
			}
                } 
	}
	return x;
}

int 
read1 (handle *h, char *byte) {
	if (h->sz == 0 || h->pos == h->sz) {
		h->sz = read4k (h->buf, h->fd);
		h->pos = 0;
	}
	*byte = *(h->buf + h->pos);
	h->pos++;
}	






