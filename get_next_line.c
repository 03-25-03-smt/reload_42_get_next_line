#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;                // будет хранить данные, которые мы уже прочитали из файла, но ещё не вернули пользователю.

	(void)fd;
	(void)stash;
	return (NULL);
}
