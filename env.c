#include "main.h"


char *_getenv(const char *name)
{
  int i, result;

  for (i = 0; environ[i]; i++)
    {
      result = _PATHstrcmp(name, environ[i]);
      if (result == 0)
	return (environ[i]);
    }
  return (NULL);
}



int _env(void)
{
  int i;

  for (i = 0; environ[i]; i++)
    _puts(environ[i]);
  return (0);
}



void _puts(char *str)
{
  int c;

  for (c = 0; str[c] != '\0'; c++)
    _putchar(str[c]);
  _putchar('\n');
}



int _putchar(char c)
{
  return (write(1, &c, 1));
}



char *_memset(char *s, char b, unsigned int n)
{
  unsigned int i;

  for (i = 0; i < n; i++)
    s[i] = b;
  return (s);
}
