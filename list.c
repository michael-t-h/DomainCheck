#include <stdlib.h>
#include <pthread.h>
#include "list.h"

void list_init(struct list *list, char **items, size_t size)
{
	list->items = items;
	list->size = size;
	pthread_mutex_init(&list->lock, NULL);
}

char *list_pop(struct list *list)
{
	pthread_mutex_lock(&list->lock);
	char *item = NULL;

	/* Find first item in list */
	for (size_t i = 0; i < list->size; i++) {
		item = list->items[i];

		/* Remove item from list */
		if (item != NULL) {
			list->items[i] = NULL;
			break;
		}
	}

	pthread_mutex_unlock(&list->lock);
	return item;
}
