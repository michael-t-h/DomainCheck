#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

size_t read_input(char ***input)
{
	char buffer[BUFFER_SIZE];
	char **lines = NULL;
	size_t line_count = 0;

	/* Read lines of input from stdin */
	while (fgets(buffer, sizeof(buffer), stdin)) {
		/* Trim leading whitespace */
		char *start;
		for (start = buffer; isspace(*start); start++);
		memmove(buffer, start, strlen(start) + 1);

		/* Trim trailing whitespace and characters */
		char *end;
		for (end = buffer; !isspace(*end) && *end != '\0'; end++);
		*end = '\0';

		/* Skip input line if empty */
		if (!strlen(buffer)) {
			continue;
		}

		/* Resize lines array */
		lines = realloc(lines, (++line_count) * sizeof(*lines));

		if (!lines) {
			exit(EXIT_FAILURE);
		}

		/* Copy input line to lines array */
		char *line = strdup(buffer);

		if (!line) {
			exit(EXIT_FAILURE);
		}

		lines[line_count - 1] = line;
	}

	*input = lines;
	return line_count;
}
