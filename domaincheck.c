#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "list.h"
#include "thread.h"

int main(int argc, char *argv[])
{
	int thread_count = 0;

	/* Parse thread count argument */
	if (argc > 1) {
		thread_count = atoi(argv[1]);
	}

	/* Verify valid argument */
	if (thread_count < 1) {
		puts("Usage: domaincheck [threads]");
		return EXIT_FAILURE;
	}

	/* Read input */
	char **lines;
	size_t line_count = read_input(&lines);

	/* Create list structure */
	struct list domains;
	list_init(&domains, lines, line_count);

	/* Create threads */
	pthread_t *threads = calloc(thread_count, sizeof(*threads));

	if(!threads) {
		return EXIT_FAILURE;
	}

	for(int i = 0; i < thread_count; i++) {
		if(pthread_create(&threads[i], NULL, thread, &domains)) {
			return EXIT_FAILURE;
		}
	}

	/* Wait for threads to finish */
	for(int i = 0; i < thread_count; i++) {
		pthread_join(threads[i], NULL);
	}

	/* Free memory */
	free(threads);

	for (size_t i = 0; i < domains.size; i++) {
		free(domains.items[i]);
	}

	free(domains.items);

	return EXIT_SUCCESS;
}
