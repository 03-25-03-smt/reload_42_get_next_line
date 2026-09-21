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

static char	*read_to_stash(int fd, char *stash)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read_buffer(fd, buffer);
	while (bytes_read > 0)
	{
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (ft_strchr(buffer, '\n'))
			break;
		bytes_read = read_buffer(fd, buffer);
	}
	free(buffer);
	return (stash);
}
