#include "main.h"

char **tokenize(char *buffer)
{
  char *token, **av, *delimiter = "\n";
  int i = 0, wordcount = 0;

  wordcount = _splitstring(buffer);
  if(!wordcount)
    return (NULL);
  av = malloc((wordcount + 1) * sizeof(char *));
  if (av == NULL)
    exit(1);
  token = _strtok(buffer, delimiter);
  while (token != NULL)
    {
      av[i] = _strdup(token);
      token = _strtok(NULL, delimiter);
      i++;
    }
  av[i] = NULL;
  return (av);
}



int _splitPATH(char *str)
{
  int i, searchflag = 1, wordcount = 0;

  for (i = 0; str[i]; i++)
    {
      if (str[i] != ':' && searchflag == 1)
	{
	  wordcount += 1;
	  searchflag = 0;
	}
      if (str[i + 1] == ':')
	searchflag = 1;
    }
  return (wordcount);
}



int _PATHstrcmp(const char *s1, const char *s2)
{
  int i;

  for (i = 0; s2[i] != '='; i++)
    {
      if(s1[i] != s2[i])
	return (-1);
    }
  return (0);
}

char *_concat(char *tmp, char **av, char *tok)
{
  int len = 0;

  _memset(tmp, 0, 256);
  len = _strlen(tok) + _strlen(av[0]) + 2;
  _strcat(tmp, tok);
  _strcat(tmp, "/");
  _strcat(tmp, av[0]);
  tmp[len - 1] = '\0';
  return (tmp);
}
