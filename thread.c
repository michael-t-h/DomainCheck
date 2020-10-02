#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "thread.h"
#include "list.h"

/* Check if domain resolves */
static bool dns_resolve(char *domain) {
	struct addrinfo *info;
	int result = getaddrinfo(domain, NULL, NULL, &info);
	
	/* Free memory if succeeded */
	if (!result) {
		freeaddrinfo(info);
	}

	return !result;
}

void *thread(void *arg)
{
	struct list *domains = (struct list *)arg;
	char *domain;

	/* Iterate domains in list */
	while ((domain = list_pop(domains)) != NULL) {
		/* Print domain if it resolves */
		if (dns_resolve(domain)) {
			puts(domain);
		}

		free(domain);
	}

	return NULL;
}
