#ifndef LIST_H
#define LIST_H

#include <pthread.h>

/* Thread-safe list implementation */
struct list {
	char **items;
	size_t size;
	pthread_mutex_t lock;
};

/* Initialise list */
void list_init(struct list *list, char **items, size_t size);
/* Remove and return first item in list, or NULL if empty */
char *list_pop(struct list *list);

#endif
