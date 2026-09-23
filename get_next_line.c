#include "get_next_line.h"

static char *fill_stash(char **stash, int fd)
{
  ssize_t	bytes;                                          // принимает отрицательные значения / для системы ввода + выводв / read(), write(), recv(), send()
	char	*temp;
	char	*buf;

  buf = malloc(BUFFER_SIZE + 1);                          // создаем строку 42 + 1
  if (!buf)
    return (NULL);
  bytes = read(fd, buf, BUFFER_SIZE);                    // сколько байт реально удалось прочитать. fd - ОТКУДА  / buf - КУДА  / BUFFER_SIZE - СКОЛЬКО МАКС
  if (bytes <= 0)
  {
    free(buf);
    if (bytes < 0)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
  }
  buf[bytes] = '\0';
  temp = ft_strjoin(*stash, buf);
  free(buf);
	free(*stash);
  *stash = temp;
  return (*stash);
}

static char *fill_line(char *stash)
{
  size_t len;
  size_t i; 
  char *line;

  len = 0;
  while (stash[len] && stash[len] != '\n')                // находим длинну len до знака '\n'
    len++;
  if (stash[len] == '\n')                                  // если мы нашли '\n' мы должны скопировать его в другую строку и вернуть "Hello\n"
    len++;
  line = malloc(len + 1;);                                // обьявляем новую строку 
  if (!line)
		return (NULL);
  i = 0;
  while (i < len)                                        // копируем строку stash[i] в line[i]
  {
    line[i] = stash[i];
    i++;
  }
  line[i] = '\0';
  return (line);
}

static char *stash_cut(char *stash)
{
  size_t i; 
  size_t len; 
  char *new; 

  i = 0;
  while (stash[i] && stash[i] != '\n')                      // находим длинну len до знака '\n'
    i++;
  if (stash[i] == '\n')                                     // переступаем '\n' чтотобы записать строку полностью 
    i++;
  len = 0;
  while (stash[i + len] != '\0')                            // считаем новую длинну строки до конца 
    len++;
  new = malloc(len + 1);
  if (!new)
		return (NULL);
  len = 0;
  while (stash[i + len] != '\0')
  {
    new[len] = stash[i + len];
    len++;
  }
  new[len] = '\0';
	return (new);
}

char	*free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
  static char *stash;                                              // static означает, что она не уничтожается после выхода из get_next_line
  char *temp; 
  char *line;

  if (!stash)                                                      // При первом вызове: stash = NULL
    stash = ft_strdup("");                                        // создаём пустую строку: stash → ""
  if (!stash)
		return (NULL);
  while ((!ft_strchr(stash, '\n')) && fill_stash(&stash, fd));    // Пока в stash нет \n и fill_stash успешно добавляет новые данные — продолжай читать.
	if (!stash)
		return (NULL);                                                // Это обработка ситуации, когда внутри fill_stash произошла ошибка чтения и она сделала: *stash = NULL
  if (!*stash)                                                    // Если нет перавого символа stash то мы очищаем полностью весь сташ 
    return (free_stash(&stash));
  line = fill_line(stash);                                        // создаем в памяти скопированую строку из сташ
	if (!line)
		return (free_stash(&stash));                                                  
  temp = stash_cut(stash);
  free(stash);
	stash = temp;
	return (line);
}


  
  
  
    
  
  
    
  
  
  
  




  
  
  
  
    
