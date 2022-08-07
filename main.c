#include "main.h"

int main(void)
{
  char **av, *PATH = NULL, *fullpathbuffer = NULL, *copy = NULL, *buffer = NULL;
  int exitstatus = 0;

  signal(SIGINT, SIG_IGN);
  PATH = _getenv("PATH");
  if (PATH == NULL)
    return (-1);
  while (1)
    {
      av = NULL;
      prompt();
      buffer = _read();
      if(*buffer != '\0')
	{
	  av = tokenize(buffer);
	  if (av == NULL)
	    {
	      free(buffer);
	      continue;
	    }
	  fullpathbuffer = _fullpathbuffer(av, PATH, copy);
	  if (checkbuiltins(av, buffer, exitstatus) == 1)
	    continue;
	  exitstatus = _forkprocess(av, buffer, fullpathbuffer);
	}
      else
	free(buffer);
    }
  return (0);
}
