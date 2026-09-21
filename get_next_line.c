#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;                // будет хранить данные, которые мы уже прочитали из файла, но ещё не вернули пользователю.

	(void)fd;
	(void)stash;
	return (NULL);
}

static ssize_t	read_buffer(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
		buffer[bytes_read] = '\0';
	return (bytes_read);
}
