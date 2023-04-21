#include <unistd.h>
/**
  * _error - basic function to print errors.
  * @str: string given to print to stderr.
  * Return: void Success=(0).
  */
void _error(char *str)
{
	int index = 0;

	for (index = 0; str[index] != '\0'; index++)
	{
		write(STDERR_FILENO, &str[index], 1);
	}
	write(STDERR_FILENO, "\n", 1);
}

/**
  * _puts - basic function to print a string.
  * @str: string given to print.
  * Return: void Success=(0).
  */
void _puts(char *str)
{
	const size_t BUF_SIZE = 1024;
	char buf[BUF_SIZE];
	size_t s_iput = 0, b_oput = 0;

	if (!str)
	{	return;	}
	while (str[s_iput] != '\0')
	{
		buf[b_oput] = str[s_iput];
		if (b_oput == BUF_SIZE || str[s_iput] == '\0')
		{
			write(STDOUT_FILENO, buf, b_oput);
			b_oput++;
		}
	}
	write(STDERR_FILENO, "\n", 1);
}
