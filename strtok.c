#include "main.h"
/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
  char *char_ptr = (char *)ptr;
  char *char_newptr = (char *)newptr;
  unsigned int i;

  for (i = 0; i < size; i++)
    char_newptr[i] = char_ptr[i];
}
/*returns the next token in a C-string*/
char *_strtok(char str[], const char *delim)
{
  static char *splitted, *str_end;
  char *str_start;
  unsigned int i, bool;

  if (str != NULL)
    {
      if (cmp_chars(str, delim))
	return (NULL);
      splitted = str;
      i = _strlen(str);
      str_end = &str[i];
    }
  str_start = splitted;
  if (str_start == str_end)
    return (NULL);

  for (bool = 0; *splitted; splitted++)
    {
      if (splitted != str_start)
	if (*splitted && *(splitted - 1) == '\0')
	  break;

      for (i = 0; delim[i]; i++)
	{
	  if (*splitted == delim[i])
	    {
	      *splitted = '\0';
	      if (splitted == str_start)
		str_start++;
	      break;
	    }
	}
      if (bool == 0 && *splitted)
	bool = 1;
    }
  if (bool == 0)
    return (NULL);
  return (str_start);
}



int cmp_chars(char str[], const char *delim)
{
  unsigned int i, j, k;

  for(i = 0, k = 0; str[i]; i++)
    {
      for (j = 0; delim[j]; j++)
	{
	  if (str[i] == delim[j])
	    {
	      k++;
	      break;
	    }
	}
    }
  if (i == k)
    return (1);
  return (0);
}
